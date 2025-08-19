/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:18:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/24 05:48:10 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdint.h>
# include "utils.h"
# include <MLX42/MLX42.h>

# define NAME_SIZE 32

typedef struct	s_object
{
	char		name[NAME_SIZE];
	uint8_t		is_name_set;
	t_transform	transform;
	void		(*render)();
  void            (*obj_info)();
}	t_object;

void	render_object(mlx_t *mlx, void *_obj, void *camera);
void	set_object_name(void *_obj, const char *name, int *id);
void    object_constructor(void *_obj);

#endif // OBJECT_H
