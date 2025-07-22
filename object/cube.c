/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/07/22 16:52:11 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"
#include <stdlib.h>
#include <libft.h>

static void set_vertices(t_vertex *vertices)
{
	vertices[0] = (t_vertex){1, 1, -5, 0, 0, 0};		// top front	0
	vertices[1] = (t_vertex){-1, 1, -5, 0, 0, 0};	// top left		1
	vertices[2] = (t_vertex){-1, 1, -7, 0, 0, 0};	// top back		2
	vertices[3] = (t_vertex){1, 1, -7, 0, 0, 0};	// top right	3
	vertices[4] = (t_vertex){1, -1, -5, 0, 0, 0};	// down front	4
	vertices[5] = (t_vertex){-1, -1, -5, 0, 0, 0};	// down left	5
	vertices[6] = (t_vertex){-1, -1, -7, 0, 0, 0};	// down back	6
	vertices[7] = (t_vertex){1, -1, -7, 0, 0, 0};	// down right	7
}

static void set_indices(uint32_t *indices, size_t count)
{
	ft_memcpy(indices, (uint32_t [36]){
						0, 1, 2, // top			0
						2, 3, 0, // top			1
						4, 5, 6, // down		2
						6, 7, 4, // down		3
						0, 1, 4, // sur top		4
						1, 2, 5, // sur top		5
						2, 3, 6, // sur top		6
						3, 0, 7, // sur top		7
						4, 5, 1, // sur down	8
						5, 6, 2, // sur down	9
						6, 7, 3, // sur down	10
						7, 4, 0	 // sur down	11
					}, count * sizeof(uint32_t));
}


t_cube *init_cube(t_vector3 pos, t_vector3 rotation, mlx_image_t *texture)
{
	t_cube 		*cube;
	static int	id;

	cube = ft_calloc(1, sizeof(*cube));
	if (!cube)
		return (NULL);
	set_object_name(cube, "cube", &id);
	model_constructor(cube);
	cube->model.obj.transform.position = pos;
	cube->model.obj.transform.rotation = rotation;
	cube->model.obj.transform.scale = (t_vector3){1.f, 1.f, 1.f};
	cube->model.texture = texture;
	cube->model.vertex_count =
	sizeof(cube->vertices) / sizeof(cube->vertices[0]);
	cube->model.index_count =
	sizeof(cube->indices) / sizeof(cube->indices[0]);
	set_vertices(cube->vertices);
	set_indices(cube->indices, cube->model.index_count);
	return (cube);
}
