#ifndef OBJ_H
#define OBJ_H

typedef int int32_t;

typedef struct s_obj
{
    int32_t x;
    int32_t y;
    void (*display)();
}   t_obj;

void    obj_display(void *_obj, char *name);
void consractor_obj(t_obj *obj, int32_t x, int32_t y);


#endif