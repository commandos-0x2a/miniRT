#include "camera.h"
#define __USE_XOPEN
#include <math.h>
#include <libft.h>
#include <stdio.h>

void	perspective_projection(t_camera *camera, t_mat4 *mat)
{
	float	focal_length;
	float	range_inv;
	float	aspect_ratio;

	ft_bzero(mat, sizeof(*mat));
	aspect_ratio = ((float)camera->width / (float)camera->height);
	// printf("width: %d, height: %d, aspect_ratio: %f\n", camera->width, camera->height, aspect_ratio);
	focal_length = 1.0f / tanf(camera->fov * 0.5f * (M_PI / 180.0f));
	range_inv = -1.0f / (camera->far - camera->near);
	mat->m[0][0] = focal_length / aspect_ratio;
	mat->m[1][1] = focal_length;
	mat->m[2][2] = (camera->far + camera->near) * range_inv;
	mat->m[2][3] = 2.0f * camera->near * camera->far * range_inv;
	mat->m[3][2] = -1.f;
}
