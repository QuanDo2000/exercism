#include "triangle.h"

int is_triangle(triangle_t sides) {
    return !(sides.a <= 0 || sides.b <= 0 || sides.c <= 0 ||
             sides.a + sides.b < sides.c ||
             sides.a + sides.c < sides.b ||
             sides.b + sides.c < sides.a);
}

int is_equilateral(triangle_t sides) {
    return is_triangle(sides) && (sides.a == sides.b && sides.b == sides.c);
}

int is_isosceles(triangle_t sides) {
    return is_triangle(sides) && (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c);
}

int is_scalene(triangle_t sides) {
    return is_triangle(sides) && (!is_isosceles(sides));
}