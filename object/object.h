/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:18:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/16 01:15:31 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

#include <MLX42/MLX42.h>
#include <stdint.h>

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
	int8_t	tex;
}	t_vertex;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct	s_object
{
	t_vector3	pos;
	t_vector3	rotation;
	void		(*render)();
}	t_object;

void	render_object(mlx_t *mlx, void *_obj, void *camera);

void    object_constructor(void *_obj);

#endif // OBJECT_H
