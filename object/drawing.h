#ifndef DRAWING_H
#define DRAWING_H

#include <MLX42/MLX42.h>

void	draw_circle(mlx_image_t *image, 
		uint32_t cx, uint32_t cy, 
		int32_t radius, uint32_t color);

void draw_line(mlx_image_t *image, int x1, int x2, int y1, int y2);


void draw_triangle(mlx_image_t *image,
			   uint32_t x1, uint32_t y1,
			   uint32_t x2, uint32_t y2,
			   uint32_t x3, uint32_t y3);

#endif // DRAWING_H