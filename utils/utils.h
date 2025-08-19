#ifndef UTILS_H
#define UTILS_H

#include <MLX42/MLX42.h>

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
}	t_vertex;

typedef struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector4;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct	s_transform
{
	t_vector3	position;
	t_vector3	rotation;
	t_vector3	scale;
}	t_transform;

typedef struct s_mat8
{
  float m[8][8];
} t_mat8;

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
void	draw_texure_triangle(mlx_image_t *image, t_vertex vertices[3], mlx_texture_t *tex);

#endif // UTILS_H
