#include "object.h"
#include <string.h>

void draw(void *_obj, mlx_image_t *frame, void *camera)
{
    t_object    *obj;
    void (*draw_func)(t_object*, mlx_image_t*, void*);
    
    obj = (t_object *)_obj;
    if (obj && obj->draw)
    {
        draw_func = obj->draw;
        draw_func(obj, frame, camera);
    }
}

void    object_constructor(void *_obj)
{
    t_object    *obj;

    obj = (t_object *)_obj;
    memset(obj, 0, sizeof(*obj));
}
