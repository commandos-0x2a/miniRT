/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:18:03 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/11 11:42:24 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <string.h>

void	draw_object(mlx_t *mlx, void *_obj, void *camera)
{
	t_object	*obj;
	void (*draw_func)(mlx_t *, t_object *, void *);

	obj = (t_object *)_obj;
	if (obj && obj->draw)
	{
		draw_func = obj->draw;
		draw_func(mlx, obj, camera);
	}
}

void	object_constructor(void *_obj)
{
	t_object	*obj;

	obj = (t_object *)_obj;
	memset(obj, 0, sizeof(*obj));
}
