/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/15 13:12:12 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "object.h"

// we either use one attribute for the camera's rotation and orientation,
// Use a single orientation attribute (e.g., quaternion or rotation matrix). 
// Each frame or input event, update this orientation with an incremental rotation:
// or we use two attributes for the camera's orientation and rotation.
typedef struct s_camera
{
	t_object		obj; // object already has position and rotation
	mlx_image_t		*frame;
	// t_vector3		position; // Position in Cartesian coordinates
	// t_vector3		orientation; // Orientation in spherical coordinates (radius, theta, phi)
	float			fov; // Field of view in degrees
	float			aspect_ratio; // Aspect ratio of the camera
	float			near; // Near clipping plane distance
	float			far; // Far clipping plane distance
	float			height; // Height of the camera's view
	float			width; // Width of the camera's view
}	t_camera;

t_camera	*init_camera(mlx_t *mlx, float fov, uint32_t frame_width, uint32_t frame_height);

#endif // CAMERA_H