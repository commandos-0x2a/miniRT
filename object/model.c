/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:24:41 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/24 15:46:42 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "camera.h"
#include <math.h>
#include "drawing.h"
#include <stdio.h>
#include <stdlib.h>

static t_vector4 vertex_2_vertor4(t_vertex ver)
{
	t_vector4 vec;

	vec.x = ver.x;
	vec.y = ver.y;
	vec.z = ver.z;
	vec.w = 1;

	return (vec);
}

static void render_model(mlx_t *mlx, t_model *model, t_camera *camera)
{
	t_mat4			transtorm_matrix;
	t_vector4		*vertices;
	t_vector4		*vertix;
	unsigned int	i;

	(void)mlx;
	get_transform_matrix(model, &transtorm_matrix);
	mat4_mult_mat4(&transtorm_matrix, transtorm_matrix, camera->matrix);
	
	vertices = malloc(model->vertex_count * sizeof(*vertices));
	if (!vertices)
		return ;
	
	i = 0;
	while (i < model->vertex_count)
	{
		vertix = &vertices[i];
		mat4_mult_vec4(vertix, &transtorm_matrix, vertex_2_vertor4(model->vertices[i]));
		if (vertix->w != 1)
		{
			vertix->x /= vertix->w;
			vertix->y /= vertix->w;
			vertix->z /= vertix->w;
		}
		vertix->x = (vertix->x + 1.f) * 0.5f * camera->width;
		vertix->y = (vertix->y + 1.f) * 0.5f * camera->height;
		i++;
	}
	i = 0;
	while (i < model->vertex_count)
	{
		draw_circle(camera->frame, vertices[i].x, vertices[i].y, 5, 0x00ff00ff);
		i++;
	}
	
	i = 0;
	while (i < model->index_count)
	{
		uint32_t i0, i1, i2;

		i0 = model->indices[i];
		i1 = model->indices[i + 1];
		i2 = model->indices[i + 2];
		
		draw_triangle(camera->frame, 
			vertices[i0].x, vertices[i0].y,
			vertices[i1].x, vertices[i1].y,
			vertices[i2].x, vertices[i2].y);
		i += 3;
	}
	
	// printf("-----------------------------------------\n");
}

void	model_constructor(void *_model)
{
	t_model		*model;
	static int	id;

	model = (t_model *)_model;
	set_object_name(model, "model", &id);
	object_constructor(model);
	model->vertices = NULL;
	model->vertex_count = 0;
	model->indices = NULL;
	model->index_count = 0;
	model->texture = NULL;
	model->obj.render = render_model;
}
