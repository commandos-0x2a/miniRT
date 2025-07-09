#include "obj.h"
#include <stdio.h>

void consractor_obj(t_obj *obj, int32_t x, int32_t y)
{
    if (!obj)
        return;
    obj->x = x;
    obj->y = y;
    obj->display = NULL;
}

void    obj_display(void *_obj, char *name)
{
    t_obj *obj = (t_obj *)_obj;
    void (*display)(t_obj *, char *name);
    if (!obj)
    {
        printf("Object is NULL\n");
        return;
    }
    display = obj->display;
    if (display)
        display(obj, name);
//     else
//         printf("Object at (%d, %d)\n", obj->x, obj->y);
}
