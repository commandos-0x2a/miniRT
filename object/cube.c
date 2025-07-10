#include "cube.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void set_vertices(vertex_t vertices[8])
{
    vertices[0] = (vertex_t){ 1, 1, 1, 0, 0, 0};
    vertices[1] = (vertex_t){ 1,-1, 1, 0, 0, 0};
    vertices[2] = (vertex_t){-1,-1, 1, 0, 0, 0};
    vertices[3] = (vertex_t){-1, 1, 1, 0, 0, 0};
    vertices[4] = (vertex_t){ 1, 1,-1, 0, 0, 0};
    vertices[5] = (vertex_t){ 1,-1,-1, 0, 0, 0};
    vertices[6] = (vertex_t){-1,-1,-1, 0, 0, 0};
    vertices[7] = (vertex_t){-1, 1,-1, 0, 0, 0};
}

static void set_indices(unsigned int indices[12 * 3])
{
    indices = (unsigned int[12 * 3]){
        
    }
}

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