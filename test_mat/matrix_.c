#include "../object/object.h"
#include <libft.h>
//test for input location
// # define _X 10
// # define _Y 20
// # define _Z 30

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

t_mat4 *set_obj_mat(t_object *obj)
{
    t_mat4 *mat;

    ft_memset(&mat, 0, sizeof(t_mat4));
    mat->buf[0][0] = 1.0f; // Set scale in x
    mat->buf[1][1] = 1.0f; // Set scale in y
    mat->buf[2][2] = 1.0f; // Set scale in z
    mat->buf[3][0] = obj->transform.position.x; // Set translation in x
    mat->buf[3][1] = obj->transform.position.y; // Set translation in y
    mat->buf[3][2] = obj->transform.position.z; // Set translation in z
    mat->buf[3][3] = 1.0f; // Set homogeneous coordinate
    mat->buf[0][3] = 0.0f; // Set homogeneous coordinate for x
    mat->buf[1][3] = 0.0f; // Set homogeneous coordinate for y
    mat->buf[2][3] = 0.0f; // Set homogeneous coordinate for z
    //set rotation matrix based on obj->transform.rotation
    return mat;
}

void	get_transform_matrix(void *_obj, t_mat4 *mat)
{
    t_object *obj;

    obj = _obj;

    (void)mat;
    (void)obj;
    // TODO: set transform matrix to mat

}


