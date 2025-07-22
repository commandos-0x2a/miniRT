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

typedef struct	s_transform
{
	t_vector3	position;
	t_vector3	rotation;
	t_vector3	scale;
}	t_transform;

typedef struct s_mat4
{
	float buf[4][4];
}	t_mat4;

typedef struct s_vec4 //this is the same as 1X4 matrix
{
	float x;
	float y;
	float z;
	float w;
}	t_vec4;


void	get_transform_matrix(void *_obj, t_mat4 *mat);

#endif // UTILS_H