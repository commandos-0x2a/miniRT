#ifndef DRAWING_H
#define DRAWING_H

#include <MLX42/MLX42.h>

void	draw_circle(mlx_image_t *image, 
		uint32_t cx, uint32_t cy, 
		int32_t radius, uint32_t color);

#endif // DRAWING_H