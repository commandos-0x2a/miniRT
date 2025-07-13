/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:40 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/13 17:06:22 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void set_vertices(vertex_t *vertices)
{
	vertices[0] = (vertex_t){1, 1, 1, 0, 0, 0};		// top front	0
	vertices[1] = (vertex_t){-1, 1, 1, 0, 0, 0};	// top left		1
	vertices[2] = (vertex_t){-1, 1, -1, 0, 0, 0};	// top back		2
	vertices[3] = (vertex_t){1, 1, -1, 0, 0, 0};	// top right	3
	vertices[4] = (vertex_t){1, -1, 1, 0, 0, 0};	// down front	4
	vertices[5] = (vertex_t){-1, -1, 1, 0, 0, 0};	// down left	5
	vertices[6] = (vertex_t){-1, -1, -1, 0, 0, 0};	// down back	6
	vertices[7] = (vertex_t){1, -1, -1, 0, 0, 0};	// down right	7
}

static void set_indices(GLuint *indices, size_t count)
{
	memcpy(indices, (GLuint [36]){
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
					}, count * sizeof(GLuint));
}


t_cube *init_cube(t_vector3 pos, t_vector3 rotation, mlx_image_t *texture)
{
	t_cube *cube;

	cube = calloc(1, sizeof(*cube));
	if (!cube)
		return (NULL);
	model_constructor(cube, cube->vertices, cube->indices);
	cube->model.obj.pos = pos;
	cube->model.obj.rotation = rotation;
	cube->model.mesh.texture = texture;
	cube->model.mesh.vertex_count =
	sizeof(cube->vertices) / sizeof(cube->vertices[0]);
	cube->model.mesh.index_count =
	sizeof(cube->indices) / sizeof(cube->indices[0]);
	//cube->geo.obj.draw = project_cube;
	memset(cube->vertices, 0, sizeof(cube->vertices));
	memset(cube->indices, 0, sizeof(cube->indices));
	set_vertices(cube->vertices);
	set_indices(cube->indices, cube->model.mesh.index_count);
	return (cube);
}
