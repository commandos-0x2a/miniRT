#include "matrix.h"
#include "log.h"
#include <stdio.h>

void ft_viz_mat4(t_mat4 m)
{
  printf("|%f  %f  %f  %f|\n", m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3]);
  printf("|%f  %f  %f  %f|\n", m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3]);
  printf("|%f  %f  %f  %f|\n", m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3]);
  printf("|%f  %f  %f  %f|\n", m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]);
}
