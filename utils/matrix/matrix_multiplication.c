/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:35:42 by rsrour            #+#    #+#             */
/*   Updated: 2025/08/05 11:56:36 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "object.h"
#include <libft.h>
#include <stdio.h>
#include "log.h"
#include "matrix.h"

/*
DOT product of two 4x4 matrices
This function multiplies two 4x4 matrices and returns the resulting matrix.
For 3D vectors, the operation is:
    A . B = A.x * B.x + A.y * B.y + A.z * B.z  + A.w * B.w
	 we need it because A and B are 4D vectors represented
	as 4x4 matrices.)
*/
void mat4_mult_mat4(t_mat4 *result, t_mat4 *a, t_mat4 *b) // TODO: don't forget to norme me
{
	result->m[0][0] += a->m[0][0] * b->m[0][0] + a->m[0][1] * b->m[1][0] + a->m[0][2] * b->m[2][0] + a->m[0][3] * b->m[3][0];
	result->m[0][1] += a->m[0][0] * b->m[0][1] + a->m[0][1] * b->m[1][1] + a->m[0][2] * b->m[2][1] + a->m[0][3] * b->m[3][1];;
	result->m[0][2] += a->m[0][0] * b->m[0][2] + a->m[0][1] * b->m[1][2] +  a->m[0][2] * b->m[2][2] + a->m[0][3] * b->m[3][2];
    result->m[0][3] += a->m[0][0] * b->m[0][3] + a->m[0][1] * b->m[1][3] + a->m[0][2] * b->m[2][3] + a->m[0][3] * b->m[3][3];
	
	result->m[1][0] += a->m[0][1] * b->m[0][0] + a->m[1][1] * b->m[0][1] + a->m[2][1] * b->m[0][2] + a->m[3][1] * b->m[0][3];
	result->m[1][1] += a->m[0][1] * b->m[1][0] + a->m[1][1] * b->m[1][1] + a->m[2][1] * b->m[1][2] + a->m[3][1] * b->m[1][3];
	result->m[1][2] += a->m[0][1] * b->m[2][0] + a->m[1][1] * b->m[2][1] + a->m[2][1] * b->m[2][2] + a->m[3][1] * b->m[2][3];
	result->m[1][3] += a->m[0][1] * b->m[3][0] + a->m[1][1] * b->m[3][1] + a->m[2][1] * b->m[3][2] + a->m[3][1] * b->m[3][3];
	result->m[2][0] += a->m[0][2] * b->m[0][0] + a->m[1][2] * b->m[0][1] + a->m[2][2] * b->m[0][2] + a->m[3][2] * b->m[0][3];
	result->m[2][1] += a->m[0][2] * b->m[1][0] + a->m[1][2] * b->m[1][1] + a->m[2][2] * b->m[1][2] + a->m[3][2] * b->m[1][3];
	result->m[2][2] += a->m[0][2] * b->m[2][0] + a->m[1][2] * b->m[2][1] + a->m[2][2] * b->m[2][2] + a->m[3][2] * b->m[2][3];
	result->m[2][3] += a->m[0][2] * b->m[3][0] + a->m[1][2] * b->m[3][1] + a->m[2][2] * b->m[3][2] + a->m[3][2] * b->m[3][3];
	result->m[3][0] += a->m[0][3] * b->m[0][0] + a->m[1][3] * b->m[0][1] + \
						a->m[2][3] * b->m[0][2] + a->m[3][3] * b->m[0][3];
	// result->m[3][1] += a->m[3][0] * b->m[0][1] + a->m[3][1] * b->m[1][1] + 
	// 					a->m[3][2] * b->m[2][1] + a->m[3][3] * b->m[3][1];
	result->m[3][1] += a->m[0][3] * b->m[1][0] + a->m[1][3] * b->m[1][1] + \
						a->m[2][3] * b->m[1][2] + a->m[3][3] * b->m[1][3];
	// result->m[3][2] += a->m[3][0] * b->m[0][2] + a->m[3][1] * b->m[1][2] + 
	// 					a->m[3][2] * b->m[2][2] + a->m[3][3] * b->m[3][2];
	result->m[3][2] += a->m[0][3] * b->m[2][0] + a->m[1][3] * b->m[2][1] + \
						a->m[2][3] * b->m[2][2] + a->m[3][3] * b->m[2][3];
	// result->m[3][3] += a->m[3][0] * b->m[0][3] + a->m[3][1] * b->m[1][3] + 
	// 					a->m[3][2] * b->m[2][3] + a->m[3][3] * b->m[3][3];
	result->m[3][3] += a->m[0][3] * b->m[3][0] + a->m[1][3] * b->m[3][1] + \
						a->m[2][3] * b->m[3][2] + a->m[3][3] * b->m[3][3];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	  {
		j = 0;
		while (j < 4)
		  {
			//if (result->m[i][j] > 1000)
			printf("m[%d][%d] = %f\n", i, j, result->m[i][j]);
			j++;
		  }
		i++;
	  }
}

void	mat3_mult_vec3(t_vector3 *result, t_mat3 *mat, t_vector3 *vec)
{
	result->x = mat->m[0][0] * vec->x + mat->m[1][0] * vec->y + mat->m[2][0] * vec->z;
	result->y = mat->m[0][1] * vec->x + mat->m[1][1] * vec->y + mat->m[2][1] * vec->z;
	result->z = mat->m[0][2] * vec->x + mat->m[1][2] * vec->y + mat->m[2][2] * vec->z;
}

void mat4_mult_vec4(t_vector4 *result, t_mat4 *mat, t_vector4 vec)
{
	result->x = mat->m[0][0] * vec.x + mat->m[1][0] * vec.y + \
			mat->m[2][0] * vec.z + mat->m[3][0] * vec.w;
	result->y = mat->m[0][1] * vec.x + mat->m[1][1] * vec.y + \
			mat->m[2][1] * vec.z + mat->m[3][1] * vec.w;
	result->z = mat->m[0][2] * vec.x + mat->m[1][2] * vec.y + \
			mat->m[2][2] * vec.z + mat->m[3][2] * vec.w;
	result->w = mat->m[0][3] * vec.x + mat->m[1][3] * vec.y + \
			mat->m[2][3] * vec.z + mat->m[3][3] * vec.w;
}
