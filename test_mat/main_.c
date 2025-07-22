#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components_.h"
#include <MLX42/MLX42.h>
#include <ft_printf.h>

#define WIDTH 1000
#define HEIGHT 800

typedef struct	s_game
{
	mlx_t		*mlx;
	t_cube		*cube;
	t_camera	*camera;
}	t_game;

void ft_draw(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->camera->aspect_ratio = ((float)game->camera->frame->width / (float)game->camera->frame->height);
	render_object(game->mlx, game->cube, game->camera);
}

void	destroy_game(t_game *game)
{
	free(game->camera);
	free(game->cube);
	printf("%s\n", __func__);
	mlx_terminate(game->mlx);
	free(game);
}

int32_t main(void)
{
	t_game	*game;

	game = calloc(1, sizeof(*game));

	LOG_INFO("test");
	// Gotta error check this stuff
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	LOG_INFO("mlx initialized");
	game->camera = init_camera(game->mlx, 45.0f, WIDTH, HEIGHT);
	if (!game->camera)
		destroy_game(game);
	game->cube = init_cube((t_vector3){0, 0, 0}, (t_vector3){0}, NULL);
	if (!game->cube)
		destroy_game(game);
	mlx_loop_hook(game->mlx, ft_draw, game);

	mlx_loop(game->mlx);
	
	destroy_game(game);
	return (EXIT_SUCCESS);
}
