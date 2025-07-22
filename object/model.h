/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:54 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 14:00:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
#define MODEL_H

#include <math.h>
#include "object.h"
# include <MLX42/MLX42.h>

typedef struct s_model
{
	t_object	obj;
	unsigned int	vertex_count; // Number of vertices in the model
	t_vertex 		*vertices; // Pointer to an array of vertex data
	unsigned int	index_count;  // Number of indices in the model
	unsigned int	*indices;  // Pointer to an array of index data
	mlx_image_t		*texture; // Pointer to the texture image

} t_model;

void	model_constructor(void *_model);

#endif // MODEL_H
