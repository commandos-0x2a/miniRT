#ifndef MATRIX_H
#define MATRIX_H

#include <MLX42/MLX42.h>
#include "utils.h"

typedef struct s_mat4
{
	float m[4][4];
}	t_mat4;

typedef struct s_mat3
{
	float	m[3][3];
}	t_mat3;

typedef struct s_rcx
{
	float	rx;
	float	ry;
	float	rz;
	float	sx;
	float	sy;
	float	sz;
	float	cx;
	float	cy;
	float	cz;
}	t_rcx;

void	get_transform_matrix(void *_obj, t_mat4 *mat);
void	mat4_mult_mat4(t_mat4 *result, t_mat4 *a, t_mat4 *b);
void	mat4_mult_vec4(t_vector4 *result, t_mat4 *mat, t_vector4 vec);
float	ft_det_mat4(t_mat4 *m);
void	ft_adjugate_mat4(t_mat4 *adj, t_mat4 *m);
void	ft_viz_mat4(t_mat4 m);
void	ft_inverse_mat4(t_mat4 *result, t_mat4 *m)

#endif
