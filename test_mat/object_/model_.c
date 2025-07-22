/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:24:41 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 14:11:07 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model_.h"
#include "camera_.h"
#include <math.h>
#include "drawing_.h"
#include <stdio.h>
#include <stdlib.h>
#include <MLX42/MLX42_Int.h>

// static void render_model(mlx_t *mlx, t_model *model, t_camera *camera)
// {
// 	uint32_t	i;
// 	uint32_t	j;
// 	mlx_image_t	*texture;

// 	mlx_ctx_t* mlxctx = mlx->context;
// 	texture = model->mesh.texture;
// 	glBindTexture(GL_TEXTURE_2D, ((mlx_image_ctx_t*)texture->context)->texture);
// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);

// 	i = 0;
// 	while (i < model->mesh.index_count)
// 	{
// 		j = 0;
// 		while (j < 3)
// 		{
// 			camera_apply_projection(camera, new_vertices + i, &model->mesh.vertices[model->mesh.indices[i]]);
// 			j++;
// 			i++;
// 		}
// 	}
// }

void	model_constructor(void *_model, 
		t_vertex *vertices, uint32_t *indices)
{
	t_model		*model;
	static int	id;

	model = (t_model *)_model;
	set_object_name(model, "model", &id);
	object_constructor(model);
	model->mesh.texture = NULL;
	model->mesh.vertices = vertices;
	model->mesh.vertex_count = 0;
	model->mesh.indices = indices;
	model->mesh.index_count = 0;
	// model->obj.render = render_model;
}
