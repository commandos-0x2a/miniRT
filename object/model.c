#include "model.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

// mlx_image_t *ft_read_texture_date(int fd, t_model *model)
// {
// 	//fill later
// }

t_model	*load_model(const char *filename)
{
	int		fd;
	t_model	model;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (NULL);
	}
	read(fd, &model, offsetof(t_model, reserved) + RESERVED_SIZE);
	model.vertices = malloc(model.vertex_count * sizeof(*model.vertices));
	read(fd, model.vertices, model.vertex_count * sizeof(*model.vertices));
	model.indices = malloc(model.index_count * sizeof(*model.indices));
	read(fd, model.indices, model.index_count * sizeof(*model.indices));
	// model.texture = ft_read_texture_data(fd, &model);
}