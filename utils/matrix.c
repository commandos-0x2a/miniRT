/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 02:01:34 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/24 14:23:04 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <libft.h>
#include <stdio.h>

/*
Start with plain scalar C, write fully unrolled mat4‑mat4 and mat4‑vec4.

Compile with optimization flags like `-O3 -march=native -ftree-vectorize`
*/

// Don't forget to account for the camera's position and orientation in the 
// transformation matrix when rendering objects in the scene. This will ensure 
// that the objects are correctly positioned and oriented relative to the 
// camera's view.

// Don't forget to account for face orientation when rendering objects. 
// (CLOCKWISE or COUNTER-CLOCKWISE)
// This will ensure that the front faces of the objects are visible and 
// correctly oriented in the camera
// view, while the back faces are culled or not rendered.


void	get_transform_matrix(void *_obj, t_mat4 *mat)
{
    t_object *obj;

    obj = _obj;
    ft_bzero(mat, sizeof(t_mat4));
    mat->m[0][0] = obj->transform.scale.x; // Set scale in x
    mat->m[1][1] = obj->transform.scale.y; // Set scale in y
    mat->m[2][2] = obj->transform.scale.z; // Set scale in z
    mat->m[3][0] = obj->transform.position.x; // Set translation in x
    mat->m[3][1] = obj->transform.position.y; // Set translation in y
    mat->m[3][2] = obj->transform.position.z; // Set translation in z
    mat->m[3][3] = 1.0f; // Set homogeneous coordinate
    mat->m[0][3] = 0.0f; // Set homogeneous coordinate for x
    mat->m[1][3] = 0.0f; // Set homogeneous coordinate for y
    mat->m[2][3] = 0.0f; // Set homogeneous coordinate for z
    //set rotation matrix based on obj->transform.rotation
}

/*
DOT product of two 4x4 matrices
This function multiplies two 4x4 matrices and returns the resulting matrix.
For 3D vectors, the operation is:
    A . B = A.x * B.x + A.y * B.y + A.z * B.z  + A.w * B.w
	 we need it because A and B are 4D vectors represented
	as 4x4 matrices.)
*/
void mat4_mult_mat4(t_mat4 *result, t_mat4 a, t_mat4 b)
{
    // TODO: convert this to hard coded
    // remove while loop

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
                result->m[i][j] += a.m[i][k] * b.m[k][j];
        }
    }
}

void mat4_mult_vec4(t_vector4 *result, t_mat4 *mat, t_vector4 vec)
{
    result->x = mat->m[0][0] * vec.x + mat->m[0][1] * vec.y + mat->m[0][2] * vec.z + mat->m[0][3] * vec.w;
    result->y = mat->m[1][0] * vec.x + mat->m[1][1] * vec.y + mat->m[1][2] * vec.z + mat->m[1][3] * vec.w;
    result->z = mat->m[2][0] * vec.x + mat->m[2][1] * vec.y + mat->m[2][2] * vec.z + mat->m[2][3] * vec.w;
    result->w = mat->m[3][0] * vec.x + mat->m[3][1] * vec.y + mat->m[3][2] * vec.z + mat->m[3][3] * vec.w;
    // printf( "% .2f = % .2f * % .2f + % .2f * % .2f + % .2f * % .2f + % .2f * % .2f\n"
    //         "% .2f = % .2f * % .2f + % .2f * % .2f + % .2f * % .2f + % .2f * % .2f\n"
    //         "% .2f = % .2f * % .2f + % .2f * % .2f + % .2f * % .2f + % .2f * % .2f\n"
    //         "% .2f = % .2f * % .2f + % .2f * % .2f + % .2f * % .2f + % .2f * % .2f\n\n",
    //     result->x, mat->m[0][0], vec.x, mat->m[0][1], vec.y, mat->m[0][2], vec.z, mat->m[0][3], vec.w,
    //     result->y, mat->m[1][0], vec.x, mat->m[1][1], vec.y, mat->m[1][2], vec.z, mat->m[1][3], vec.w,
    //     result->z, mat->m[2][0], vec.x, mat->m[2][1], vec.y, mat->m[2][2], vec.z, mat->m[2][3], vec.w,
    //     result->w, mat->m[3][0], vec.x, mat->m[3][1], vec.y, mat->m[3][2], vec.z, mat->m[3][3], vec.w);
}
