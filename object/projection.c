/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:46:38 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/15 13:40:14 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include "camera.h"
#include <unistd.h>
#include <stdio.h>

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

void ft_perspective_projection(t_vector3 *vec, t_camera *camera)
{
    float range_inv;
    float projected_z;
    float projected_x;
    float projected_y;
    float focal_length;
    float w;

    if (!vec)
        return;
    focal_length = 1.0f / tanf(camera->fov * 0.5f * (M_PI / 180.0f));
    range_inv = -1.0f / (camera->far - camera->near);
    // M[0][0] = focal_length / aspect_ratio;
    projected_x = (focal_length / camera->aspect_ratio) * vec->x;
    // M[1][1] = focal_length;
    projected_y = focal_length * vec->y;
    // M[2][2] = (far + near) * range_inv;
    // M[2][3] = (-2.0* far * near) * range_inv;
    projected_z = ((camera->far + camera->near) * range_inv) * vec->z + (2.0f * camera->near * camera->far * range_inv);
    // M[3][2] = -1
    w = -vec->z; // Assuming w is the homogeneous coordinate, set it to -z for perspective division
    if (w != 0.0f)
    {
        projected_x /= w;
        projected_y /= w;
        projected_z /= w;
    }
    vec->x = (projected_x + 1.0f) * 0.5f * camera->width; // Adjust x based on aspect ratio
    vec->y = (1.0f - projected_y) * 0.5f * camera->height; // Adjust y based on focal length
    vec->z = projected_z;
}

