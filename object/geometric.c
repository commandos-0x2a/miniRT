#include "geometric.h"
#include "camera.h"
#include <math.h>
#include "drawing.h"

// test draw with opneGL (not work)
/*
int8_t mlx_bind_texture(mlx_ctx_t* mlx, mlx_image_t* img);

void	draw_geometric(mlx_t *mlx, t_geometric *geo, 
			mlx_image_t *frame, t_camera *camera)
{
	(void)frame; (void)camera; (void)geo;
	mlx_ctx_t* mlxctx = mlx->context;
	mlx_list_t* imglst = mlxctx->images;

	// Upload image textures to GPU
	while (imglst)
	{
		mlx_image_t* image;
		if (!(image = imglst->content)) {
			mlx_error(MLX_INVIMG);
			return;
		}

		glBindTexture(GL_TEXTURE_2D, ((mlx_image_ctx_t*)image->context)->texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
		imglst = imglst->next;
	}

	// Execute draw calls
	int8_t tex = 0; //mlx_bind_texture(mlxctx, geo->texture);

	vertex_t *vertices = malloc(geo->vertices_count * sizeof(vertex_t));
	if (!vertices)
		return ;
	float	uv[3][2] = {
		{0.0f, 0.0f},
		{1.0f, 0.0f},
		{0.0f, 1.0f}
	};
	for (unsigned int i = 0; i < geo->vertices_count; i++)
	{
		vertices[i] = (vertex_t){
			fmaxf(geo->vertices[i].x * 100.f + 300.f, 0.f),
			fmaxf(geo->vertices[i].y * 100.f + 300.f, 0.f),
			0,
			uv[i % 3][0],
			uv[i % 3][1],
			tex
		};
	}
	memmove(mlxctx->batch_vertices + mlxctx->batch_size,
		vertices, geo->vertices_count * sizeof(vertex_t));
	free(vertices);
	mlxctx->batch_size += geo->vertices_count;

	if (mlxctx->batch_size >= MLX_BATCH_SIZE)
		mlx_flush_batch(mlxctx);
}
*/

void	draw_geometric(mlx_t *mlx, t_geometric *geo, t_camera *camera) // frame inside camera
{
	(void)mlx; (void)geo; (void)camera;
#ifdef DEBUG
	printf("mlx: %p, goe: %p, camera: %p\n", mlx, geo, camera);
	printf("vertices: %u\n", geo->vertices_count);
	for (uint32_t i = 0; i < geo->vertices_count; i++)
	{
		printf("\tx:% 2f y:% 2f z:% 2f u:% 2f v:% 2f tex:%hhd\n",
			geo->vertices[i].x,
			geo->vertices[i].y,
			geo->vertices[i].z,
			geo->vertices[i].u,
			geo->vertices[i].v,
			geo->vertices[i].tex
		);
	}
	printf("\nindices: %u\n", geo->indices_count);
	for (uint32_t i = 0; i < geo->indices_count; i+=3)
	{
		printf("\t%u, %u, %u\n", 
			geo->indices[i],
			geo->indices[i + 1],
			geo->indices[i + 2]
		);
	}
#endif

	draw_circle(camera->frame, 50, 49, 50, 0xff0000ff);
	// write draw code here
	
}

void	geometric_constructor(void *_geo, 
		vertex_t *vertices, GLuint *indices)
{
	t_geometric	*geo;

	geo = (t_geometric *)_geo;
	object_constructor(geo);
	geo->texture = NULL;
	geo->vertices = vertices;
	geo->vertices_count = 0;
	geo->indices = indices;
	geo->indices_count = 0;
	geo->obj.draw = draw_geometric;
}
