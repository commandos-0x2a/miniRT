/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/13 17:00:30 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "geometric.h"
#include "../projection/projection.h"

typedef struct s_cube
{
	t_geometric	geo;
	vertex_t	vertices[8];
	GLuint		indices[12 * 3];
}	t_cube;

t_cube	*init_cube(t_vector3 pos, t_vector3 rotation, mlx_image_t *texture);

#endif // CUBE_H