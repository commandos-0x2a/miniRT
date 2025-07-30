/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barycentric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:54:19 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/07/25 08:59:12 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <MLX42/MLX42.h>

static void	get_barycentric_matrix(t_mat3 *result, t_vertex p[3])
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

static void	get_texure_coordinate(t_vector2 *res, t_vector3 lambda, t_vertex vertices[3])
{
	res->x = lambda.x * vertices[0].u + lambda.y * vertices[1].u + lambda.z * vertices[2].u;
	res->y = lambda.x * vertices[0].v + lambda.y * vertices[1].v + lambda.z * vertices[2].v;
}

static uint32_t	get_texure_pixel(mlx_texture_t *tex, uint32_t x, uint32_t y)
{
	uint32_t color = ((uint32_t *)tex->pixels)[y * tex->width + x];
	return (color << 8 | color >> 24);
}

void	draw_texure_triangle(mlx_image_t *image, t_vertex vertices[3], mlx_texture_t *tex)
{
	t_mat3		mat;
	t_vector3	lambda;
	t_vector2	tex_coord;

	get_barycentric_matrix(&mat, vertices);

	float sx = (fminf(vertices[0].x, fminf(vertices[1].x, vertices[2].x)));
	float sy = (fminf(vertices[0].y, fminf(vertices[1].y, vertices[2].y)));
	float ex = (fmaxf(vertices[0].x, fmaxf(vertices[1].x, vertices[2].x)));
	float ey = (fmaxf(vertices[0].y, fmaxf(vertices[1].y, vertices[2].y)));
	for (float y = sy; y <= ey; y++)
	{
		for (float x = sx; x <= ex; x++)
		{
			mat3_mult_vec3(&lambda, &mat, (t_vector3){1, x, y});
			if (lambda.x < 0.f || lambda.x > 1.f 
				|| lambda.y < 0.f || lambda.y > 1.f 
				|| lambda.z < 0.f || lambda.z > 1.f)
				continue;
			get_texure_coordinate(&tex_coord, lambda, vertices);
			mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, get_texure_pixel(tex, tex_coord.x, tex_coord.y));
		}
	}
}
