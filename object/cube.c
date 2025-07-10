#include "cube.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_cube* cube_create(t_vector3 pos, t_vector3 rotation)
{
    t_cube  *cube;

    cube = calloc(1, sizeof(*cube));
    if (!cube)
        return (NULL);
    geometric_constructor(cube, cube->vertices, cube->indices);
    cube->geo.obj.pos = pos;
    cube->geo.obj.rotation = rotation;
    cube->geo.vertices_count = 
            sizeof(cube->vertices) / sizeof(cube->vertices[0]);
    cube->geo.indices_count = 
            sizeof(cube->indices) / sizeof(cube->indices[0]);
    memset(cube->vertices, 0, sizeof(cube->vertices));
    memset(cube->indices, 0, sizeof(cube->indices));
    return (cube);
}