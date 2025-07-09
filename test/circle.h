#ifndef CIRCLE_H
#define CIRCLE_H

#include "obj.h"

typedef struct s_circle
{
    t_obj obj; // Inherit from t_obj
    // Circle-specific properties
    int32_t radius;
} t_circle;

t_circle *init_circle(int32_t x, int32_t y, int32_t radius);

#endif