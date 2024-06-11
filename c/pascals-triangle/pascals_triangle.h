#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stddef.h>
#include <stdint.h>

#define MIN_ROWS 1

void free_triangle(uint8_t **triangle, size_t rows);
uint8_t **create_triangle(size_t rows);

#endif
