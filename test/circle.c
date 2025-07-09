#include "circle.h"
#include <stdlib.h>
#include <stdio.h>

static void display(t_circle *circle)
{
    printf("Circle at (%d, %d)\n", circle->obj.x, circle->obj.y);
    printf("Circle radius: %d\n", circle->radius);
}

t_circle *init_circle(int32_t x, int32_t y, int32_t radius)
{
    t_circle *circle = malloc(sizeof(t_circle));
    if (!circle)
        return NULL;
    consractor_obj((t_obj *)circle, x, y);
    circle->obj.display = display;
    circle->radius = radius;
    return circle;
}
