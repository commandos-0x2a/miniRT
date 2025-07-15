#include "model.h"
#include "camera.h"
#include <math.h>
#include "drawing.h"
#include <stdio.h>

static void	remap_uv(mlx_image_t *frame, t_vertex vertices[3], mlx_image_t *texture)
{
	(void)texture;

	for (int i = 0; i < 3; i++)
	{
		printf("%s i=%i x=%2f y=%2f\n", __func__, i, vertices[i].x, vertices[i].y);
		draw_circle(frame, vertices[i].x, vertices[i].y, 5, 0xff0000ff);
	}
}

static void draw_model(mlx_t *mlx, t_model *model, t_camera *camera)
{
	(void)mlx;
	(void)model;
	(void)camera;
	t_vertex	vertices[3];
	uint32_t	i;

	i = 0;
	while (i < model->mesh.vertex_count)
	{
		camera_apply_projection(camera, vertices, model->mesh.vertices + i);
		remap_uv(camera->frame, vertices, NULL);
		i += 3;
	}
}

void	model_constructor(void *_model, 
		t_vertex *vertices, uint32_t *indices)
{
	t_model	*model;

	model = (t_model *)_model;
	object_constructor(model);
	model->mesh.texture = NULL;
	model->mesh.vertices = vertices;
	model->mesh.vertex_count = 0;
	model->mesh.indices = indices;
	model->mesh.index_count = 0;
	model->obj.draw = draw_model;
}
