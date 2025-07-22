#include "camera.h"
#define __USE_XOPEN
#include <math.h>
#include <libft.h>

void	perspective_projection(t_camera *camera, t_mat4 *mat)
{
	float	focal_length;
	float	range_inv;

	ft_bzero(mat, sizeof(*mat));
	focal_length = 1.0f / tanf(camera->fov * 0.5f * (M_PI / 180.0f));
	range_inv = -1.0f / (camera->far - camera->near);
	mat->buf[0][0] = focal_length / camera->aspect_ratio;
	mat->buf[1][1] = focal_length;
	mat->buf[2][2] = (camera->far + camera->near) * range_inv;
	mat->buf[2][3] = 2.0f * camera->near * camera->far * range_inv;
	mat->buf[3][2] = -1.f;
}
