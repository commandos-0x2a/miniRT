/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/24 12:44:55 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "model.h"

typedef struct s_cube
{
	t_model		model;
	t_vertex	vertices[8];
	uint32_t	indices[12 * 3];
}	t_cube;

t_cube	*init_cube(mlx_image_t *texture);

#endif // CUBE_H