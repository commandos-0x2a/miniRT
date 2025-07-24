// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 500


uint32_t ft_pixel(float r, float g, float b, float a)
{
	uint32_t	_r;
	uint32_t	_g;
	uint32_t	_b;
	uint32_t	_a;

	_r = r * 255.f;
	_g = g * 255.f;
	_b = b * 255.f;
	_a = a * 255.f;
    return (_r << 24 | _g << 16 | _b << 8 | _a);
}

typedef struct s_mat3
{
	float	m[3][3];
}	t_mat3;

typedef struct s_vector3
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

void	mat3_mult_vec3(t_vector3 *result, t_mat3 *mat, t_vector3 vec)
{
	result->x = mat->m[0][0] * vec.x + mat->m[0][1] * vec.y + mat->m[0][2] * vec.z;
	result->y = mat->m[1][0] * vec.x + mat->m[1][1] * vec.y + mat->m[1][2] * vec.z;
	result->z = mat->m[2][0] * vec.x + mat->m[2][1] * vec.y + mat->m[2][2] * vec.z;
}

void	get_barycentric_matrix(t_mat3 *result, t_vector2 p[3])
{
	float a2 = 1.f /
		(p[0].x * (p[1].y - p[2].y)
		+ p[1].x * (p[2].y - p[0].y)
		+ p[2].x * (p[0].y - p[1].y));

	result->m[0][0] = a2 * (p[1].x * p[2].y - p[2].x * p[1].y);
	result->m[0][1] = a2 * (p[1].y - p[2].y);
	result->m[0][2] = a2 * (p[2].x - p[1].x);

	result->m[1][0] = a2 * (p[2].x * p[0].y - p[0].x * p[2].y);
	result->m[1][1] = a2 * (p[2].y - p[0].y);
	result->m[1][2] = a2 * (p[0].x - p[2].x);

	result->m[2][0] = a2 * (p[0].x * p[1].y - p[1].x * p[0].y);
	result->m[2][1] = a2 * (p[0].y - p[1].y);
	result->m[2][2] = a2 * (p[1].x - p[0].x);
}

void	get_texure_coordinate(t_vector2 *res, t_vector3 lambda, t_vector2 p[3])
{
	res->x = lambda.x * p[0].x + lambda.y * p[1].x + lambda.z * p[2].x;
	res->y = lambda.x * p[0].y + lambda.y * p[1].y + lambda.z * p[2].y;
}

uint32_t	get_image_pixel(mlx_texture_t *tex, uint32_t x, uint32_t y)
{
	uint32_t color = ((uint32_t *)tex->pixels)[y * tex->width + x];
	return (color << 8 | color >> 24);
}

void	draw_triangle(mlx_image_t *image, mlx_texture_t *tex, t_vector2 tex_ver[3])
{
	t_vector2 p[3] = {
		{0.f, 0.f},
		{(float)image->width, (float)image->height},
		{0.f, (float)image->height}
	};

	t_mat3		mat;
	t_vector3	lambda;
	t_vector2	tex_coord;

	get_barycentric_matrix(&mat, p);

	float sx = (fminf(p[0].x, fminf(p[1].x, p[2].x)));
	float sy = (fminf(p[0].y, fminf(p[1].y, p[2].y)));
	float ex = (fmaxf(p[0].x, fmaxf(p[1].x, p[2].x)));
	float ey = (fmaxf(p[0].y, fmaxf(p[1].y, p[2].y)));
	for (float y = sy; y <= ey; y++)
	{
		for (float x = sx; x <= ex; x++)
		{
			mat3_mult_vec3(&lambda, &mat, (t_vector3){1, x, y});
			if (lambda.x < 0.f || lambda.x > 1.f 
				|| lambda.y < 0.f || lambda.y > 1.f 
				|| lambda.z < 0.f || lambda.z > 1.f)
				continue;
			get_texure_coordinate(&tex_coord, lambda, tex_ver);
			mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, get_image_pixel(tex, tex_coord.x, tex_coord.y));
		}
	}
}

int32_t main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Barycentric coordinate system", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_texture_t *tex = mlx_load_png("./equal.png");

	t_vector2 tex_ver[3] = {
		{0.f, 0.f},
		{(float)tex->width, 0.f},
		{0.f, (float)tex->height}
	};
	draw_triangle(image, tex, tex_ver);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
