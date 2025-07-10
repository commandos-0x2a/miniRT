#ifndef CAMERA_H
# define CAMERA_H

#include "object.h"

typedef struct s_camera
{
	t_object obj;
	float fov;
}	t_camera;

#endif // CAMERA_H