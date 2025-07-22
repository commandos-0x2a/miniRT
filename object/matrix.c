/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 02:01:34 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/21 11:58:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

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
    (void)mat;
    (void)obj;
    // TODO: set transform matrix to mat
}

/*
DOT product of two 4x4 matrices
This function multiplies two 4x4 matrices and returns the resulting matrix.
For 3D vectors, the operation is:
    A . B = A.x * B.x + A.y * B.y + A.z * B.z  + A.w * B.w
	 we need it because A and B are 4D vectors represented
	as 4x4 matrices.)
*/

t_mat4 dot_m4m4(t_mat4 a, t_mat4 b)
{
    t_mat4 result = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
                result.buf[i][j] += a.buf[i][k] * b.buf[k][j];
        }
    }
    return result;
}
