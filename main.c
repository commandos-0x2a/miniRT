#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components.h"


int	main()
{
	t_cube		*cube;
	t_camera	camera;

	object_constructor(&camera);

	camera.obj.pos.x = 10;
	camera.fov = 60.0f;

	cube = cube_create((t_vector3){0, 0, 0}, (t_vector3){0});

	draw(cube, NULL, NULL);

	free(cube);
}