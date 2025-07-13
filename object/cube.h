/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/11 08:57:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "model.h"

typedef struct s_cube
{
	t_model		model;
	vertex_t	vertices[8];
	GLuint		indices[12 * 3];
}	t_cube;

t_cube	*init_cube(t_vector3 pos, t_vector3 rotation, mlx_image_t *texture);

#endif // CUBE_H