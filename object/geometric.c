#include "geometric.h"
#include "camera.h"

static void	draw_geometric(t_geometric *geo, 
			mlx_image_t *frame, t_camera *camera)
{
	printf("geometric: %p, frame: %p, camera: %p\n", 
		geo, frame, camera);
	printf("vertices: %d\n", geo->vertices_count);
	for (unsigned int i = 0; i < geo->vertices_count; i++)
	{
		printf("\tx:% f, y:% f, z:% f, v:% f, u:% f, tex% hhd\n", 
			geo->vertices[i].x,
			geo->vertices[i].y,
			geo->vertices[i].z,
			geo->vertices[i].u,
			geo->vertices[i].v,
			geo->vertices[i].tex
		);
	}
	printf("indices: %d\n", geo->indices_count);
	for (unsigned int i = 0; i < geo->indices_count; i+=3)
	{
		printf("\t% d, % d, % d\n", 
			geo->indices[i],
			geo->indices[i + 1],
			geo->indices[i + 2]
		);
	}
}

void	geometric_constructor(void *_geo, 
		vertex_t *vertices, GLuint *indices)
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