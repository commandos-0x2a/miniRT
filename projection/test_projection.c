#include <stdio.h>
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// #include "projection.h"

# define FOV 45.0f
# define NEAR 1.0f
# define FAR 100.0f
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080


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
    geo->vertices[0] = (t_vec3){200, 200, 30};
    geo->vertices[1] = (t_vec3){300, 200, 30};
    geo->vertices[2] = (t_vec3){300, 300, 30};
    geo->vertices[3] = (t_vec3){200, 300, 30};
    geo->vertices[4] = (t_vec3){200, 200, 2};
    geo->vertices[5] = (t_vec3){300, 200, 2};
    geo->vertices[6] = (t_vec3){300, 300, 2};
    geo->vertices[7] = (t_vec3){200, 300, 2};
    // Define cube indices for drawing triangles
    unsigned int indices[] = {
        0, 2, 1, 2, 3, 0, // top
        4, 5, 6, 6, 7, 4, // bottom
        0, 1, 4, 1, 2, 5, // front
        2, 3, 6, 3, 0, 7, // back
        4, 5, 1, 5, 6, 2, // left
        6, 7, 3, 7, 4, 0  // right
    };
    for (int i = 0; i < geo->indices_count; i++)
        geo->indices[i] = indices[i];
    return geo;
}

//the z axis is positive towards the viewer and negative away from the viewer
void ft_perspective_projection(t_vec3 *vec, float fov, float aspect_ratio, 
    float near, float far)//, int screen_width, int screen_height)
{
    float range_inv;
    float projected_z;
    float projected_x;
    float projected_y;
    float focal_length;

    if (!vec)
        return;
    focal_length = 1.0f / tanf(fov * 0.5f * (M_PI / 180.0f));
    range_inv = -1.0f / (far - near);

    //Apply perspective projection
    // M[0][0] = focal_length / aspect_ratio;
    projected_x = (focal_length / aspect_ratio) * vec->x;
    // M[1][1] = focal_length;
    projected_y = focal_length * vec->y;
    projected_z = ((far + near) * range_inv) * vec->z + (2.0f * near * far * range_inv);
    vec->x = projected_x; // Adjust x based on aspect ratio
    vec->y = projected_y; // Adjust y based on focal length
    vec->z = projected_z;
}

void ft_apply_projection(t_geometric *geo, mlx_image_t *image)//, float fov, 
    //float aspect_ratio, float near, float far, mlx_image_t *image)
{
    printf("Applying perspective projection...\n");
    printf("Vertices count: %d\n", geo->vertices_count);
    float aspect_ratio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
    printf("Aspect ratio: %f\n", aspect_ratio);
    for (int i = 0; i < geo->vertices_count; i++)
    {
        printf("Vertex %d: x: %f, y: %f, z: %f\n", i, geo->vertices[i].x, geo->vertices[i].y, geo->vertices[i].z);
        ft_perspective_projection(&geo->vertices[i], FOV, aspect_ratio, NEAR, FAR);
        // Check bounds before drawing
        fprintf(stderr, "after projection: x: %f, y: %f, z: %f\n", vec->x, vec->y, vec->z);
        mlx_put_pixel(image, (int)geo->vertices[i].x, (int)geo->vertices[i].y, 0xFFFFFF);
    }
}

void ft_draw_cube(mlx_image_t *image, t_geometric *geo)
{
    for (int i = 0; i < geo->indices_count; i += 3)
    {
        // Draw triangles using the indices
        int v1 = geo->indices[i];
        int v2 = geo->indices[i + 1];
        int v3 = geo->indices[i + 2];
        
        // Draw lines between vertices (simple line drawing)
        mlx_put_pixel(image, (int)geo->vertices[v1].x, (int)geo->vertices[v1].y, 0xAAAFFF);
        mlx_put_pixel(image, (int)geo->vertices[v2].x, (int)geo->vertices[v2].y, 0xAAAFFF);
        mlx_put_pixel(image, (int)geo->vertices[v3].x, (int)geo->vertices[v3].y, 0xAAAFFF);
    }
    printf("finished drawing cube\n");
}

// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int main()
{
    t_geometric *cube;
    mlx_t *mlx;

    mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Projection Test", true);
    if (!mlx)
    {
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }
    mlx_image_t *image = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!image)
    {
        puts(mlx_strerror(mlx_errno));
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }
    mlx_image_to_window(mlx, image, 0, 0);
    fprintf(stderr, "mlx_image_to_window: %s\n", mlx_strerror(mlx_errno));
    cube = ft_create_cube();
    fprintf(stderr, "ft_create_cube: %s\n", mlx_strerror(mlx_errno));
    ft_draw_cube(image, cube);
    ft_apply_projection(cube, image);//, 45.0f, aspect_ratio, 1.0f, 100.0f, image);
    mlx_loop(mlx);
    mlx_delete_image(mlx, image);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
