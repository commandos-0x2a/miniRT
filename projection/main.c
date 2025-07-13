#include "projection.h"

#define WIDTH 1080
#define HEIGHT 720

// void ft_draw(void *param)
// {
	
// 	draw(param, game->cube, game->camera);
// }

// int32_t main()
// {
//     mlx_t *mlx;

//     if (!(mlx = mlx_init(WIDTH, HEIGHT, "Projection Example", true)))
//     {
//         puts(mlx_strerror(mlx_errno));
//         return (EXIT_FAILURE);
//     }
//     t_camera *camera = init_camera(mlx, 60, WIDTH, HEIGHT);
//     if (!camera)
//     {
//         mlx_terminate(mlx);
//         puts("Failed to initialize camera");
//         return (EXIT_FAILURE);
//     }
//     t_cube *cube = init_cube((t_vector3){0, 0, 0}, (t_vector3){0}, NULL);
//     if (!cube)
//     {
//         free(camera);
//         mlx_terminate(mlx);
//         puts("Failed to initialize cube");
//         return (EXIT_FAILURE);
//     }
//     mlx_loop_hook(mlx, ft_draw, cube);
//     mlx_loop(mlx);
    
//     free(camera);
//     free(cube);
//     mlx_terminate(mlx);
//     return (EXIT_SUCCESS);
// }