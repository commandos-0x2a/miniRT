/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:17:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/24 05:40:57 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "object.h"
#include "matrix.h"

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
	float			near; // Near clipping plane distance
	float			far; // Far clipping plane distance
	int				height; // Height of the camera's view
	int				width; // Width of the camera's view
	t_mat4			matrix;
	void			(*projection)();
}	t_camera;

t_camera	*init_camera(mlx_t *mlx, float fov, uint32_t frame_width, uint32_t frame_height);
void		camera_apply_projection(t_camera *camera, t_vertex dst[3], t_vertex *src_v3); // TODO: remove this
void		update_camera_matrix(t_camera *camera); // TODO: 

#endif // CAMERA_H
