#include "utils.h"
#include <libft.h>
#incldue <log.h>
#include <stdio.h>

static t_mat8  ft_create_augment(t_mat4 *m)
{
  t_mat8 augment_mat;

  ft_memset(&augment_mat, 0, sizeof(augment_mat));
  augment_mat[0][0] = m[0][0];
  augment_mat[0][1] = m[0][1];
  augment_mat[0][2] = m[0][2];
  augment_mat[0][3] = m[0][3];
  augment_mat[1][0] = m[1][0];
  augment_mat[1][1] = m[1][1];
  augment_mat[1][2] = m[1][2];
  augment_mat[1][3] = m[1][3];
  augment_mat[2][0] = m[2][0];
  augment_mat[2][1] = m[2][1];
  augment_mat[2][2] = m[2][2];
  augment_mat[2][3] = m[2][3];
  augment_mat[3][0] = m[3][0];
  augment_mat[3][1] = m[3][1];
  augment_mat[3][2] = m[3][2];
  augment_mat[3][3] = m[3][3];
  augment_mat[0][4] = 1;
  augment_mat[1][5] = 1;
  augment_mat[2][6] = 1;
}

void ft_inverse_mat4(t_mat4 *result, t_mat *m)
{
  t_mat8 augment_mat;

  augment_mat = ft_create_augment(m);
  
}
