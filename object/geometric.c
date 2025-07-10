#include "geometric.h"
#include "camera.h"

static void	draw_geometric(t_geometric *geo, 
			mlx_image_t *frame, t_camera *camera)
{
	printf("geometric: %p, frame: %p, camera: %p\n", 
		geo, frame, camera);
	printf("vertices: %p, indices: %p\n", geo->vertices, geo->indices);
}

void	geometric_constructor(void *_geo, 
		vertex_t *vertices, t_vector3 *indices)
{
	t_geometric	*geo;

	geo = (t_geometric *)_geo;
	object_constructor(geo);
	geo->vertices = vertices;
	geo->vertices_count = 0;
	geo->indices = indices;
	geo->indices_count = 0;
	geo->obj.draw = draw_geometric;
}