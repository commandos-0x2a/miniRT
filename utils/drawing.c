#include <MLX42/MLX42.h>
#include <math.h>
#include <stdio.h>
#include <log.h>

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void draw_circle(mlx_image_t *image,
				 uint32_t cx, uint32_t cy,
				 uint32_t radius, uint32_t color)
{
	// printf("x:%u y:%u r:%u\n", cx, cy, radius);
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



// DrawLine(mlx_image_t *image, int x1, int x2, int y1, int y2) {
//     int x = x1;
//     int y = y1;
//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int d = 2 * dy - dx; // discriminator
//     // Euclidean distance of point (x,y) from line (signed)
//     float D = 0; 
//     // Euclidean distance between points (x1, y1) and (x2, y2)
//     float length = sqrt(dx * dx + dy * dy); 
//     float _sin = dx / length;
//     float _cos = dy / length;
//     while (x <= x2) {
//         mlx_put_pixel(image, x, y - 1, D + _cos);
//         mlx_put_pixel(x, y, D);
//         mlx_put_pixel(x, y + 1, D - _cos);
//         x = x + 1;
//         if (d <= 0) {
//             D = D + _sin;
//             d = d + 2 * dy;
//         } else {
//             D = D + _sin - _cos;
//             d = d + 2 * (dy - dx);
//             y = y + 1;
//         }
//     }
// }

void draw_line(mlx_image_t *image, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	float m = 0;
	if (dx != 0)
		m = (float)dy / (float)dx;
	int x;
	int y;

	// printf(
	// 	"line x1: %d, y1: %d"
	// 	"  x2: %d, y2: %d\n",
	// 	x1, y1,
	// 	x2, y2
	// );
	if (x1 == x2)
	{
		y = (y1 < y2) ? y1 : y2;
		x = x1;
		while (y <= ((y1 > y2) ? y1 : y2))
		{
			if (y >= 0 && y < (int)image->height && x >= 0 && x < (int)image->width)
				mlx_put_pixel(image, x, y, 0xff0000ff);
			y++;
		}
	}
	else if (x1 < x2)
	{
		x = x1;
		while (x <= x2)
		{
			y = m * (x - x1) + y1;
			if (y >= 0 && y < (int)image->height && x >= 0 && x < (int)image->width)
				mlx_put_pixel(image, x, y, 0xff0000ff);
			x++;
		}
	}
	else
	{
		x = x2;
		while (x <= x1)
		{
			y = m * (x - x2) + y2;
			if (y >= 0 && y < (int)image->height && x >= 0 && x < (int)image->width)
				mlx_put_pixel(image, x, y, 0xff0000ff);
			x++;
		}
	}
}

void draw_line2(mlx_image_t *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    
    while (1)
	{
		if (y0 >= 0 && y0 < (int)image->height && x0 >= 0 && x0 < (int)image->width)
        	mlx_put_pixel(image, x0, y0, 0x0000ffff);
        int  e2 = 2 * error;
        if (e2 >= dy)
		{
            if (x0 == x1) 
				break;
            error = error + dy;
            x0 = x0 + sx;
		}
        if (e2 <= dx)
		{
            if (y0 == y1) 
				break;
            error = error + dx;
            y0 = y0 + sy;
		}
	}
}

uint32_t umin(uint32_t a, uint32_t b)
{
	return (a < b) ? a : b;
}

uint32_t umax(uint32_t a, uint32_t b)
{
	return (a > b) ? a : b;
}

void draw_triangle(mlx_image_t *image,
			   uint32_t x1, uint32_t y1,
			   uint32_t x2, uint32_t y2,
			   uint32_t x3, uint32_t y3)
{
	// printf(
	// 	"triangle x1: %u, y1: %u"
	// 	"  x2: %u, y2: %u"
	// 	"  x3: %u, y3: %u\n",
	// 	x1, y1,
	// 	x2, y2,
	// 	x3, y3
	// );

	draw_line2(image, x1, y1, x2, y2);
	draw_line2(image, x2, y2, x3, y3);
	draw_line2(image, x3, y3, x1, y1);
}