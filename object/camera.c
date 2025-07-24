#include "camera.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <libft.h>
#include "projection.h"
/*
	generate `projection_matrix` from camera projection
	and
*/
void	update_camera_matrix(t_camera *camera)
{
	void	(*projection)(t_camera *, t_mat4 *);
	t_mat4	proj_mat;
	t_mat4	transform_mat;

	memset(&camera->matrix, 0, sizeof(camera->matrix));
	memset(&proj_mat, 0, sizeof(proj_mat));
	memset(&transform_mat, 0, sizeof(transform_mat));
	projection = camera->projection;
	if (projection)
		projection(camera, &proj_mat);
	get_transform_matrix(camera, &transform_mat);

	mat4_mult_mat4(&camera->matrix, proj_mat, transform_mat);
	// TODO: multi proj_mat * transform_mat
	// set result to camera matrix
}

t_camera	*init_camera(mlx_t *mlx, float fov, uint32_t frame_width, uint32_t frame_height)
{
	t_camera	*camera;
	static int	id;

	camera = ft_calloc(1, sizeof(*camera));
	if (!camera)
		return (NULL);
	set_object_name(camera, "camera", &id);
	object_constructor(camera);
	camera->fov = fov;
	camera->width = frame_width;
	camera->height = frame_height;
	camera->frame = mlx_new_image(mlx, frame_width, frame_height);
	if (!camera->frame)
	{
		free(camera);
		return (NULL);
	}
	if (mlx_image_to_window(mlx, camera->frame, 0, 0) == -1)
	{
		free(camera);
		puts(mlx_strerror(mlx_errno));
		return (NULL);
	}
	camera->projection = perspective_projection;
	camera->near = 1.f;
	camera->far = 100.f;
	return (camera);
}





/*
void old_perspective_projection(t_camera *camera, t_vertex *dst, t_vertex *src)
{
	float	range_inv;
	float	projected_z;
	float	projected_x;
	float	projected_y;
	float	focal_length;
	float	w;

	focal_length = 1.0f / tanf(camera->fov * 0.5f * (M_PI / 180.0f));
	range_inv = -1.0f / (camera->far - camera->near);
	// M[0][0] = focal_length / aspect_ratio;
	projected_x = (focal_length / camera->aspect_ratio) * (src->x * 100.f);
	// M[1][1] = focal_length;
	projected_y = focal_length * (src->y * 100.f);
	// M[2][2] = (far + near) * range_inv;
	// M[2][3] = (-2.0* far * near) * range_inv;
	projected_z = ((camera->far + camera->near) * range_inv) * (src->z * 100.f) + (2.0f * camera->near * camera->far * range_inv);
	// M[3][2] = -1
	w = -(src->z * 100.f); // Assuming w is the homogeneous coordinate, set it to -z for perspective division
	if (w != 0.0f)
	{
		projected_x /= w;
		projected_y /= w;
		projected_z /= w;
	}
	dst->x = (projected_x + 1.0f) * 0.5f * camera->frame->width;  // Adjust x based on aspect ratio
	dst->y = (1.0f - projected_y) * 0.5f * camera->frame->height; // Adjust y based on focal length
	dst->z = projected_z;
	dst->u = src->u;
	dst->v = src->v;
	dst->tex = src->tex;
}

void	camera_apply_projection(t_camera *camera, t_vertex dst[3], t_vertex *src_v3)
{
	void	(*projection)(t_camera *, t_vertex *, t_vertex *);
	int	i;

	projection = camera->projection;
	if (!projection)
		return;
	i = 0;
	while (i < 3)
	{
		projection(camera, &dst[i], &src_v3[i]);
		printf("[%2f, %2f, %2f] => [%2f, %2f]\n", src_v3[i].x, src_v3[i].y, src_v3[i].z, dst[i].x, dst[i].y);
		i++;
	}
}
*/