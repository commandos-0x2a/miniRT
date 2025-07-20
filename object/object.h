/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:18:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/20 21:21:05 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <MLX42/MLX42.h>
# include <stdint.h>
# include "utils.h"

# define NAME_SIZE 32

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
	int8_t	tex;
}	t_vertex;

typedef struct	s_object
{
	char		name[NAME_SIZE];
	t_transform	transform;
	void		(*render)();
}	t_object;

void	render_object(mlx_t *mlx, void *_obj, void *camera);

void    object_constructor(void *_obj);

#endif // OBJECT_H
