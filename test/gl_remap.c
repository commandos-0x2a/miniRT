#include <MLX42/MLX42.h>
#include <MLX42/MLX42_Int.h>
#include "model.h"

static int8_t mlx_bind_texture(mlx_ctx_t* mlx, mlx_image_t* img)
{
	const GLint handle = (GLint)((mlx_image_ctx_t*)img->context)->texture;

	// Attempt to bind the texture, or obtain the index if it is already bound.
	for (int8_t i = 0; i < 16; i++)
	{
		if (mlx->bound_textures[i] == handle)
			return (i);

		if (mlx->bound_textures[i] == 0)
		{
			mlx->bound_textures[i] = handle;

			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, handle);
			return (i);
		}
	}

	// If no free slot was found, flush the batch and assign the texture to the first available slot
	mlx_flush_batch(mlx);

	mlx->bound_textures[0] = handle;
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, handle);
	return (0);
}

void	render_model(mlx_t *mlx, mlx_image_t *texture, 
					t_vertex *vertices, uint32_t vertex_count)
{

	int8_t tex = mlx_bind_texture(mlx, texture);

	if (mlxctx->batch_size + vertex_count >= MLX_BATCH_SIZE)
		mlx_flush_batch(mlx);
	memmove(mlxctx->batch_vertices + mlxctx->batch_size, vertices, sizeof(t_vertex) * vertex_count);
	mlxctx->batch_size += vertex_count;
}