#include <stdio.h>
#include <MLX42/MLX42.h>
#include <stdlib.h>
// #include "projection.h"

typedef struct s_camera
{
    float   x;
    float   y;
    float   z;
}   t_camera;

typedef struct s_vec3
{
    float   x;
    float   y;
    float   z;
} t_vec3;

typedef struct s_projection
{
    t_vec3  position;
    t_vec3  rotation;
}   t_projection;

typedef struct s_geometric
{
    t_vec3  *vertices;
    int32_t  vertices_count;
    unsigned int *indices;
    int32_t indices_count;
}   t_geometric;

t_geometric *ft_create_cube()
{
    t_geometric *geo = malloc(sizeof(t_geometric));
    if (!geo)
        return NULL;
    geo->vertices_count = 8;
    geo->indices_count = 36; // 6 faces * 2 triangles * 3 vertices
    geo->vertices = malloc(geo->vertices_count * sizeof(t_vec3));
    geo->indices = malloc(geo->indices_count * sizeof(unsigned int));
    if (!geo->vertices || !geo->indices)
    {
        free(geo->vertices);
        free(geo->indices);
        free(geo);
        return NULL;
    }
    // Define cube vertices
    geo->vertices[0] = (t_vec3){-1, -1, -1};
    geo->vertices[1] = (t_vec3){1, -1, -1};
    geo->vertices[2] = (t_vec3){1, 1, -1};
    geo->vertices[3] = (t_vec3){-1, 1, -1};
    geo->vertices[4] = (t_vec3){-1, -1, 1};
    geo->vertices[5] = (t_vec3){1, -1, 1};
    geo->vertices[6] = (t_vec3){1, 1, 1};
    geo->vertices[7] = (t_vec3){-1, 1, 1};
    // Define cube indices for drawing triangles
    unsigned int indices[] = {
        0, 2, 1, 2, 3, 0, // top
        4, 5, 6, 6, 7, 4, // bottom
        
    };
    for (int i = 0; i < geo->indices_count; i++)
        geo->indices[i] = indices[i];
    return geo;
}

t_geometric *ft_create_square()
{
    int i;

    i = 0;
    t_geometric *geo = malloc(sizeof(t_geometric));
    if (!geo)
        return NULL;

    geo->vertices_count = 4;
    geo->indices_count = 6; // 2 triangles * 3 vertices
    geo->vertices = malloc(geo->vertices_count * sizeof(t_vec3));
    geo->indices = malloc(geo->indices_count * sizeof(unsigned int));
    if (!geo->vertices || !geo->indices)
    {
        free(geo->vertices);
        free(geo->indices);
        free(geo);
        return NULL;
    }
    // Define square vertices
    geo->vertices[0] = (t_vec3){100, 100, 0};
    geo->vertices[1] = (t_vec3){100, 200, 0};
    geo->vertices[2] = (t_vec3){200, 100, 0};
    geo->vertices[3] = (t_vec3){200, 200, 0};
    // Define square indices for drawing triangles
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    while(i < geo->indices_count)
    {
        geo->indices[i] = indices[i];
        i++;
    }
    return geo;
}


t_geometric *ft_create_triangle()
{
    int i;

    i = 0;
    t_geometric *geo = malloc(sizeof(t_geometric));
    if (!geo)
        return NULL;
    geo->vertices_count = 3;
    geo->indices_count = 3; // 1 triangle * 3 vertices
    geo->vertices = malloc(geo->vertices_count * sizeof(t_vec3));
    geo->indices = malloc(geo->indices_count * sizeof(unsigned int));
    if (!geo->vertices || !geo->indices)
    {
        free(geo->vertices);
        free(geo->indices);
        free(geo);
        return NULL;
    }
    // Define triangle vertices
    geo->vertices[0] = (t_vec3){100, 100, 0};
    geo->vertices[1] = (t_vec3){100, 200, 0};
    geo->vertices[2] = (t_vec3){200, 100, 0};
    // Define triangle indices for drawing
    unsigned int indices[] = {0, 1, 2};
    while(i < geo->indices_count)
    {
        geo->indices[i] = indices[i];
        i++;
    }
    return geo;
}

void ft_fill_geo(t_geometric *geo, mlx_image_t *image)
{
    int i;
    int p;
    t_vec3 vec;

    i = 0;
    p = 0;
    if (!geo || !image)
        return;
    while (i < geo->vertices_count)
    {
        vec = geo->vertices[i];
        mlx_put_pixel(image, geo->vertices[i].x, geo->vertices[i].y, 0xFFFFFF);
        i++;
    }
}


int main()
{
    t_geometric *tri;
    mlx_t *mlx;

    mlx = mlx_init(800, 600, "Projection Test", true);
    if (!mlx)
    {
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }
    mlx_image_t *image = mlx_new_image(mlx, 800, 600);
    if (!image)
    {
        puts(mlx_strerror(mlx_errno));
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }
    mlx_image_to_window(mlx, image, 0, 0);
    tri = ft_create_triangle();
    ft_fill_geo(tri, image);
    // mlx_put_pixel(image, vec.x, vec.y, 0xFFFFFF);
    // mlx_put_pixel(image, vec2.x, vec2.y, 0xFFFFFF);
    // mlx_put_pixel(image, vec3.x, vec3.y, 0xFFFFFF);
    // mlx_put_pixel(image, vec4.x, vec4.y, 0xFFFFFF);
    mlx_loop(mlx);
    mlx_delete_image(mlx, image);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
