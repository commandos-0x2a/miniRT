/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:46:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/13 17:20:01 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

/*
A camera's frustum can be thought of as 6 planes, and any objects between 
those planes are visible and within the camera's field of view. Frustums 
are generally defined in terms of the near and far planes' distance from 
the camera on the Z axis, and how far the frustum extends on the near plane 
to the left, right, top and bottom from the Z axis
*/

/*
I want to create the plane of the world that the camera is looking at,
and then set the cube onto that plane.
Then set the camera at some point in the world, and set the camera's
position and rotation to look at the cube.
Then I want to project the cube onto the camera's frame, and draw it.

Yacoub wants me to create the part of projecting the 3d model into the screen
and then we build the camera and the cube around the projection logic.

How long can Yacoub wait for me to finish this? I don't know, 
but I will try to do it.
*/

// void project_cube(mlx_t *mlx, t_cube *cube, t_camera *camera)
// {
//     // This function will project the cube onto the camera's frame
//     // For now, we will just draw the cube on the camera's frame
//     // In the future, we will implement the projection logic
//     // if (cube && camera)
//     // {
//     //     draw(mlx, &cube->geo.obj, camera);
//     // }
// }