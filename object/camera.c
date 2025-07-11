#include "camera.h"
#include <stdlib.h>
#include <stdio.h>

t_camera	*init_camera(mlx_t *mlx, float fov, uint32_t frame_width, uint32_t frame_height)
{
	t_camera	*camera;

	camera = malloc(sizeof(camera));
	if (!camera)
		return (NULL);
	object_constructor(camera);
	camera->fov = fov;
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
	return (camera);
}
