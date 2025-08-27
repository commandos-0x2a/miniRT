#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"
#include <MLX42/MLX42.h>
#include "log.h"
#include "matrix.h"
#include "test.h" //test

#define WIDTH 1000
#define HEIGHT 800

typedef struct	s_game
{
	mlx_t		*mlx;
	t_cube		*cube;
	t_camera	*camera;
}	t_game;

void	destroy_game(t_game *game)
{
	free(game->camera);
	free(game->cube);
	printf("%s\n", __func__);
	mlx_terminate(game->mlx);
	free(game);
}

void ft_draw(void *param)
{
	t_game	*game;
	t_camera *camera;

	game = (t_game *)param;
	camera = game->camera;

	ft_bzero(camera->frame->pixels, camera->width * camera->height * 4);
	update_camera_matrix(game->camera);
	render_object(game->mlx, game->cube, game->camera);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_object	*player;

	game = param;
	player = (t_object *)game->camera;
	if (keydata.key == MLX_KEY_A)
		player->transform.position.x += 0.01f;
	else if (keydata.key == MLX_KEY_D)
		player->transform.position.x -= 0.01f;
	else if (keydata.key == MLX_KEY_W)
		player->transform.position.z -= 0.01f;
	else if (keydata.key == MLX_KEY_S)
		player->transform.position.z += 0.01f;
	else if (keydata.key == MLX_KEY_Q)
		player->transform.position.y += 0.01f;
	else if (keydata.key == MLX_KEY_E)
		player->transform.position.y -= 0.01f;
	else
		return;
	// printf("player move (%2f, %2f, %2f)\n", 
	// 	player->transform.position.x,
	// 	player->transform.position.y,
	// 	player->transform.position.z);
}
 
int32_t main(void)
{
	t_game			*game;
	mlx_texture_t	*tex;
	t_mat4			m;
	t_vector4		v;
	t_vector4			res;

	LOG_DEBUG("start");
	game = ft_calloc(1, sizeof(*game));
	//testing
	ft_memset(&m, 0, sizeof(m));
	ft_memset(&v, 0, sizeof(v));
	ft_memset(&res, 0, sizeof(res));
	new_mat(&m);
	new_vec4(&v);
	mat4_mult_vec4(&res, &m, v);
	LOG_INFO("m:\n");
	ft_viz_mat4(m);
	LOG_INFO("v:\n");
	ft_viz_vec4(v);
	LOG_INFO("res:\n");
	ft_viz_vec4(res);
	//end tesing
	// Gotta error check this stuff
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	tex = mlx_load_png("uv_cube.png");
	if (!tex)
		destroy_game(game);
	game->cube = init_cube(NULL);
	if (!game->cube)
		destroy_game(game);
	game->camera = init_camera(game->mlx, 45.0f, WIDTH, HEIGHT);
	if (!game->camera)
		destroy_game(game);
	mlx_loop_hook(game->mlx, ft_draw, game);
        mlx_key_hook(game->mlx, key_hook, game);
		//	mlx_one_loop(game->mlx);
	
	destroy_game(game);
	return (EXIT_SUCCESS);
}
