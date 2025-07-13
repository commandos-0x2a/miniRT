#include "model.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

// mlx_image_t *ft_read_texture_date(int fd, t_model *model)
// {
// 	//fill later
// }

int	load_mesh(t_mesh *mesh, const char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (-1);
	}
	read(fd, mesh, offsetof(t_mesh, reserved) + RESERVED_SIZE);
	mesh->vertices = malloc(mesh->vertex_count * sizeof(*mesh->vertices));
	read(fd, mesh->vertices, mesh->vertex_count * sizeof(*mesh->vertices));
	mesh->indices = malloc(mesh->index_count * sizeof(*mesh->indices));
	read(fd, mesh->indices, mesh->index_count * sizeof(*mesh->indices));
	// model.texture = ft_read_texture_data(fd, &model);
	return (0);
}