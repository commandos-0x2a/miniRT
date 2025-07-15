// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"
#include <MLX42/MLX42.h>
#include "projection.h"

#define WIDTH 1080
#define HEIGHT 720

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
	draw(game->mlx, game->cube, game->camera);
}

void	destroy_game(t_game *game)
{
	free(game->camera);
	free(game->cube);
	mlx_terminate(game->mlx);
	free(game);
	exit(0);
}

int32_t main(void)
{
	t_game	*game;

	game = calloc(1, sizeof(*game));


	// Gotta error check this stuff
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	game->camera = init_camera(game->mlx, 60, WIDTH, HEIGHT);
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


