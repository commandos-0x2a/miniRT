#include <MLX42/MLX42.h>
#include <math.h>
#include <stdio.h>

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_circle(mlx_image_t *image, 
		uint32_t cx, uint32_t cy, 
		uint32_t radius, uint32_t color)
{
	// printf("%s: x=%u y=%u\n", __func__, cx, cy);
	for (uint32_t y = 0; y < radius * 2; y++)
	{
		if (cy + y < radius || cy + y >= image->height + radius)
				continue;
		for (uint32_t x = 0; x < radius * 2; x++)
		{
			if (cx + x < radius || cx + x >= image->width + radius)
				continue;
			uint32_t dis = (x - radius) * (x - radius) + (y - radius) * (y - radius);
			
			if (dis <= powf(radius, 2.f))
			{
				mlx_put_pixel(image, 
					cx + x - radius,
					cy + y - radius,
					color);
			}
		}
	}
}
