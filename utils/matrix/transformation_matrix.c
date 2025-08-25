/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 02:01:34 by rsrour            #+#    #+#             */
/*   Updated: 2025/08/05 12:06:33 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <libft.h>
#include <stdio.h>
#include <math.h>
#include "log.h"
#include "matrix.h"

//ALL OUR WORK WILL BE COLUMN MAJOR to follow OPENGL conventions
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

/*
For each angle theta_x, theta_y, and theta_z, the rotation matrix is defined as follows:
Rotation around the x-axis:
Rx =  | 1       0    0       0 |
	  | 0   cos(x)  -sin(x)  0 |
	  | 0   sin(x)   cos(x)  0 |
	  | 0       0    0       1 |

Rotation around the y-axis:
Ry =  | cos(y)  0   sin(y)  0 |
	  | 0       1      0    0 |
	  | -sin(y) 0   cos(y)  0 |
	  | 0       0      0    1 |

Rotation around the z-axis:
Rz =  | cos(z)  -sin(z)  0   0 |
	  | sin(z)   cos(z)  0   0 |
	  | 0        0       1   0 |
	  | 0        0       0   1 |
*/

/*
The transformation matrix is built by applying scale, then rotation, and finally translation.
1 - scale
	| sx  0   0   0 |
	| 0   sy  0   0 |
	| 0   0   sz  0 |
	| 0   0   0   1 |
2 - rotation: result of Euler rotations (e.g. Rz * Ry * Rx)
3 - translation: 
	| 1   0   0   tx |
	| 0   1   0   ty |
	| 0   0   1   tz |
	| 0   0   0   1  |
*/

/*
mat.m[i][j] represents the element in the i-th column and j-th row of the matrix.
so: m[0] is the first column, m[1] is the second column, and so on.
| m[0][0] m[1][0] m[2][0] m[3][0] |   ← top row
| m[0][1] m[1][1] m[2][1] m[3][1] |   ← 2nd row
| m[0][2] m[1][2] m[2][2] m[3][2] |   ← 3rd row
| m[0][3] m[1][3] m[2][3] m[3][3] |   ← bottom row

*/

void  ft_get_scale_mat(t_object *obj, t_mat4 *scale_mat)
{
	scale_mat->m[0][0] = obj->transform.scale.x;
	scale_mat->m[1][1] = obj->transform.scale.y;
	scale_mat->m[2][2] = obj->transform.scale.z;
	scale_mat->m[3][3] = 1.0f;
}

static void ft_init_rcx(t_rcx *rcx, t_object *obj)
{
	rcx->rx = obj->transform.rotation.x * (M_PI / 180.0f); // Convert degrees to radians
	rcx->ry = obj->transform.rotation.y * (M_PI / 180.0f);
	rcx->rz = obj->transform.rotation.z * (M_PI / 180.0f);
	rcx->sx = sinf(rcx->rx);
	rcx->sy = sinf(rcx->ry);
	rcx->sz = sinf(rcx->rz);
	rcx->cx = cosf(rcx->rx);
	rcx->cy = cosf(rcx->ry);
	rcx->cz = cosf(rcx->rz);
}

//I will be using rcx struct to hold the rotation angles and sine and cosine values
// to minimize computations and for norme purposes
void 	ft_get_rotation_mat(t_object *obj, t_mat4 *rotation_mat)
{
	t_rcx rcx;
	
	ft_init_rcx(&rcx, obj);
	rotation_mat->m[0][0] = rcx.cy * rcx.cz;
	rotation_mat->m[1][0] = rcx.sz * rcx.cy;
	rotation_mat->m[2][0] = -rcx.sy;
	rotation_mat->m[0][1] = rcx.cz * rcx.sy * rcx.sx - rcx.sz * rcx.cx;
	rotation_mat->m[1][1] = rcx.sz * rcx.sy * rcx.sx + rcx.cz * rcx.cx;
	rotation_mat->m[2][1] = rcx.cy * rcx.sx;
	rotation_mat->m[0][2] = rcx.cz * rcx.sy * rcx.cx + rcx.sz * rcx.sx;
	rotation_mat->m[1][2] = rcx.sz * rcx.sy * rcx.cx - rcx.cz * rcx.sx;
	rotation_mat->m[2][2] = rcx.cy * rcx.cx;
	rotation_mat->m[3][3] = 1.0f;
}

void	ft_get_transition_mat(t_object *obj, t_mat4 *trans_mat)
{
	ft_bzero(trans_mat, sizeof(t_mat4));
	trans_mat->m[0][0] = 1.0f;
	trans_mat->m[1][1] = 1.0f;
	trans_mat->m[2][2] = 1.0f; 
	trans_mat->m[3][3] = 1.0f;
	trans_mat->m[3][0] = obj->transform.position.x; // Set translation
	trans_mat->m[3][1] = obj->transform.position.y; // Set translation
	trans_mat->m[3][2] = obj->transform.position.z; // Set translation
}

void	get_transform_matrix(void *_obj, t_mat4 *mat)
{
    t_object *obj;
	t_mat4 scale_mat;
	t_mat4 rotation_mat;
	t_mat4 translation_mat;
	t_mat4 temp_mat;

    obj = _obj;
	ft_memset(&scale_mat, 0, sizeof(t_mat4));
	ft_memset(&rotation_mat, 0, sizeof(t_mat4));
	ft_memset(&translation_mat, 0, sizeof(t_mat4));
    ft_get_scale_mat(obj, &scale_mat);
	printf("scale mat:\n");
	ft_viz_mat4(scale_mat);
	ft_get_rotation_mat(obj, &rotation_mat);
	printf("rotation_mat:\n");
	ft_viz_mat4(rotation_mat);
	ft_get_transition_mat(obj, &translation_mat);
	printf("translation_mat:\n");
	ft_viz_mat4(translation_mat);
	mat4_mult_mat4(&temp_mat, &rotation_mat, &scale_mat);
	printf("temp matrix:\n");
	ft_viz_mat4(temp_mat);
	mat4_mult_mat4(mat, &temp_mat, &translation_mat);
	printf("%s transform matrix:\n", obj->name);
	ft_viz_mat4(*mat);
}
