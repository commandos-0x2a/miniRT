#ifndef UTILS_H
#define UTILS_H

#include <MLX42/MLX42.h>
#include "matrix.h"

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	float	u;
	float	v;
}	t_vertex;

typedef struct	s_transform
{
	t_vector3	position;
	t_vector3	rotation;
	t_vector3	scale;
}	t_transform;

void	draw_texure_triangle(mlx_image_t *image, t_vertex vertices[3], mlx_texture_t *tex);

#endif // UTILS_H    
