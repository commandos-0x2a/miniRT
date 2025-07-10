/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/10 23:29:25 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include "geometric.h"

typedef struct s_cube
{
	t_geometric	geo;
	vertex_t	vertices[8];
	GLuint		indices[12 * 3];
}	t_cube;

t_cube	*cube_create(t_vector3 pos, t_vector3 rotation);

#endif // CUBE_H