/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/11 09:06:14 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "object.h"

typedef struct s_camera
{
	t_object	obj;
	mlx_image_t	*frame;
	float		fov;
}	t_camera;

t_camera	*init_camera(mlx_t *mlx, float fov, uint32_t frame_width, uint32_t frame_height);

#endif // CAMERA_H