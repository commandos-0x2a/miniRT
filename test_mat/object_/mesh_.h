#ifndef MESH_H
#define MESH_H

#include <MLX42/MLX42.h>

# define RESERVED_SIZE 32

typedef struct s_mesh {
	unsigned char	magic[4]; // Magic number to identify the file format
	unsigned int	version;   // Version of the file format
	unsigned int	vertex_count; // Number of vertices in the model
	unsigned int	index_count;  // Number of indices in the model
	unsigned int	uv_size; // Size of UV data
	unsigned char	reserved[RESERVED_SIZE]; // Reserved for future use
	t_vertex 		*vertices; // Pointer to an array of vertex data
	unsigned int	*indices;  // Pointer to an array of index data
	mlx_image_t		*texture; // Pointer to the texture image
} t_mesh;

#endif	// MESH_H