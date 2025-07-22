#include "object_.h"

//test for input location
# define _X 10
# define _Y 20
# define _Z 30

//we will recieve the location of the object in the .rt file

void mat4_mult_vec4(t_mat4 *mat, t_vector3 *vec, t_vector3 *result)
{
    result->x = mat->buf[0][0] * vec->x + mat->buf[0][1] * vec->y + mat->buf[0][2] * vec->z;// + mat->buf[0][3] * vec->w;
    result->y = mat->buf[1][0] * vec->x + mat->buf[1][1] * vec->y + mat->buf[1][2] * vec->z;// + mat->buf[1][3] * vec->w;
    result->z = mat->buf[2][0] * vec->x + mat->buf[2][1] * vec->y + mat->buf[2][2] * vec->z;// + mat->buf[2][3] * vec->w;
    //result->w = mat->buf[3][0] * vec->x + mat->buf[3][1] * vec->y + mat->buf[3][2] * vec->z;// + mat->buf[3][3] * vec->w;
}

// we should first set the transform matrix coff based on input data, and default values,
// then we use

void	get_transform_matrix(void *_obj, t_mat4 *mat)
{
    t_object *obj;

    obj = _obj;

    (void)mat;
    (void)obj;
    // TODO: set transform matrix to mat

}


