#include <MLX42/MLX42.h>
#include "log.h"

#define WIDTH 1000
#define HEIGHT 800

typedef struct s_pnt
{
  float x;
  float y;
  float z;
  float w;
}	t_pnt;

typedef struct s_camera
{
  mlx_image_t	*frame;
  float			fov;
  float			near;
  float			far;
  int			height;
  int			width;
  void			(*projection)();
}	t_camera;

t_pnt ft_init_pnt()
{
  t_pnt pnt;

  pnt.x = 1;
  pnt.y = 1;
  pnt.z = 1;
  pnt.w = 1;
  return (pnt);
}

t_camera *ft_init_camera(mlx_t *mlx)
{
  t_camera *camera;

  camera = ft_calloc(1, sizeof(*camera));
  if (!camera)
	return (NULL);
  camera->frame = mlx_new_image(mlx, WIDTH, HEIGHT);
  if (!camera->frame)
  {
	  free(camera);
	  return (NULL);
  }
  camera->fov = 45.0f;
  camera->height = HEIGHT;
  camera->width = WIDTH;
  camera->near = 1.0f;
  camera->far = 100.0f;
  return (camera);
}

int32_t main()
{
	mlx_t	 *mlx;
	t_pnt	 pnt;
	t_camera *camera;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT_rebuild", true);
	if (!mlx)
	  {
		//puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	  }
	pnt = ft_init_pnt();
	LOG_INFO("pnt: <%f, %f, %f, %f>", pnt.x, pnt.y, pnt.z, pnt.w);
	camera = ft_init_camera(mlx);
	if (!camera)
	  return (EXIT_FAILURE);
	
	ft_bzero(camera->frame->pixels, camera->width * camera->height * 4);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
