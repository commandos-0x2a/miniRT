#include "circle.h"

int main()
{
    t_circle   *circle;

    circle = init_circle(100, 200, 30);
    obj_display(circle, "My Circle");
}