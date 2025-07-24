#ifndef UTILS_H
#define UTILS_H

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
	int8_t	tex;
}	t_vertex;

typedef struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct	s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector4;

typedef struct	s_transform
{
	t_vector3	position;
	t_vector3	rotation;
	t_vector3	scale;
}	t_transform;

typedef struct s_mat4
{
	float m[4][4];
}	t_mat4;

void	get_transform_matrix(void *_obj, t_mat4 *mat);
void	mat4_mult_mat4(t_mat4 *result, t_mat4 a, t_mat4 b);
void	mat4_mult_vec4(t_vector4 *result, t_mat4 *mat, t_vector4 vec);

#endif // UTILS_H