#ifndef CUBE_H
#define CUBE_H

#include "geometric.h"

typedef struct s_cube
{
	t_geometric	geo;
	vertex_t	vertices[8];
	t_vector3	indices[12 * 3];
}	t_cube;

t_cube	*cube_create(t_vector3 pos, t_vector3 rotation);

#endif // CUBE_H