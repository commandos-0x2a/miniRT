/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:54 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 14:08:24 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
#define MODEL_H

#include <math.h>
#include "object_.h"
#include "mesh_.h"

typedef struct s_model
{
	t_object	obj;
	t_mesh		mesh;
} t_model;

void	model_constructor(void *_mod, 
		t_vertex *vertices, uint32_t *indices);

#endif // MODEL_H
