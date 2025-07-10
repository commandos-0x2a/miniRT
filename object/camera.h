#ifndef CAMERA_H
# define CAMERA_H

#include "object.h"

typedef struct s_camera
{
	t_object obj;
	float fov;
	float aspect_ratio;
}	t_camera;

#endif // CAMERA_H