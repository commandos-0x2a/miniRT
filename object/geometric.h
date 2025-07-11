/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:54 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/11 11:39:22 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include <math.h>
#include <MLX42/MLX42_Int.h>
#include "object.h"

typedef struct s_geometric
{
	t_object obj;
	mlx_image_t		*texture;
	vertex_t		*vertices;
	unsigned int	vertices_count;
	GLuint			*indices;
	unsigned int	indices_count;
} t_geometric;

void	geometric_constructor(void *_geo, 
		vertex_t *vertices, GLuint *indices);

#endif // GEOMETRIC_H
