#ifndef UTILS_H
#define UTILS_H

#include <MLX42/MLX42.h>
//#include "matrix.h"

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

void	draw_texure_triangle(mlx_image_t *image, t_vertex vertices[3], mlx_texture_t *tex);

#endif // UTILS_H    
