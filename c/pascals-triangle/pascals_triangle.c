#include "pascals_triangle.h"

#include <stdlib.h>

uint8_t** create_triangle(size_t rows) {
    uint8_t** triangle;
    if (rows <= 1) {
        triangle = calloc(MIN_ROWS, sizeof(uint8_t*));
        triangle[0] = calloc(MIN_ROWS, sizeof(uint8_t));
    } else {
        triangle = calloc(rows, sizeof(uint8_t*));
        for (size_t i = 0; i < rows; i++) {
            triangle[i] = calloc(rows, sizeof(uint8_t));
        }
    }

    if (rows >= 1) triangle[0][0] = 1;
    for (size_t i = 1; i < rows; i++) {
        triangle[i][0] = 1;
        for (size_t j = 1; j < rows; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

void free_triangle(uint8_t** triangle, size_t rows) {
    if (rows <= 1) {
        free(triangle[0]);
        free(triangle);
    } else {
        for (size_t i = 0; i < rows; i++) {
            free(triangle[i]);
        }
        free(triangle);
    }
}