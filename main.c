#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"


int	main()
{
	t_cube	*cube;

	cube = cube_create((t_vector3){10, 10, 0}, (t_vector3){0});

	draw(cube, NULL, NULL);

	free(cube);
}