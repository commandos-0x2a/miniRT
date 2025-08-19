#include "cube.h"
#include <stdlib.h>
#include <libft.h>
#include <log.h>

void ft_cube_info(t_cube *cube)
{
  t_vector3 position;
  t_vector3 rotation;
  t_vector3 scale;
  unsigned int i;

  i = 0;
  position = cube->model.obj.transform.position;
  rotation = cube->model.obj.transform.rotation;
  scale = cube->model.obj.transform.scale;
  LOG_DEBUG("cude info:");
  LOG_DEBUG("position: <%f, %f, %f>", position.x, position.y, position.z);
  LOG_DEBUG("rotation: <%f, %f, %f>", rotation.x, rotation.y, rotation.z);
  LOG_DEBUG("scale: <%f, %f, %f>", scale.x, scale.y, scale.z);
  LOG_DEBUG("vertices:");
  while(i < cube->model.vertex_count)
  {
    LOG_DEBUG("v_%d: <%f, %f, %f, %f, %f>", i, cube->vertices[i].x,
	      cube->vertices[i].y, cube->vertices[i].z, cube->vertices[i].u,
	      cube->vertices[i].v);
    i++;
  }
}
