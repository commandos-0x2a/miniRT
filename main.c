// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"
#include <MLX42/MLX42.h>
#include "log.h"

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

	LOG_DEBUG("start");
	game = ft_calloc(1, sizeof(*game));

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

	mlx_loop(game->mlx);
	
	destroy_game(game);
	return (EXIT_SUCCESS);
}
