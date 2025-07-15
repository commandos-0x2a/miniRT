/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:54 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/13 17:26:35 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
#define MODEL_H

#include <math.h>
#include "object.h"
#include "mesh.h"

typedef struct s_model
{
	t_object	obj;
	t_mesh		mesh;
} t_model;

void	model_constructor(void *_mod, 
		t_vertex *vertices, uint32_t *indices);

#endif // MODEL_H
