/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:18:03 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:32 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <string.h>
#include "log.h"

void	render_object(mlx_t *mlx, void *_obj, void *camera)
{
	t_object	*obj;
	void (*render_func)(mlx_t *, t_object *, void *);

	obj = (t_object *)_obj;
	if (obj && obj->render)
	{
		render_func = obj->render;
		render_func(mlx, obj, camera);
	}
}

void	set_object_name(void *_obj, const char *name, int *id)
{
	t_object	*obj;

	obj = _obj;
	if (!obj->is_name_set)
	{
		ft_snprintf(obj->name, sizeof(obj->name), "%s %d", name, (*id)++);
		obj->is_name_set = 1;
	}
}

void	object_constructor(void *_obj)
{
	t_object	*obj;
	static int	id;

	obj = (t_object *)_obj;
	set_object_name(obj, "object", &id);
	LOG_DEBUG("init %s", obj->name);
}
