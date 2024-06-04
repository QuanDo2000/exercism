#include "spiral_matrix.h"

#include <stdlib.h>

spiral_matrix_t* spiral_matrix_create(int size) {
    spiral_matrix_t* matrix = calloc(1, sizeof(spiral_matrix_t));
    matrix->size = size;
    if (size == 0) {
        return matrix;
    }

    matrix->matrix = calloc(size, sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix->matrix[i] = calloc(size, sizeof(int));
    }

    int x = 0, y = 0, dx = 0, dy = 1;
    for (int i = 0; i < size * size; i++) {
        matrix->matrix[x][y] = i + 1;

        int nx = x + dx, ny = y + dy;
        if (nx >= size || nx < 0 || ny >= size || ny < 0 || matrix->matrix[nx][ny] != 0) {
            int t = -dx;
            dx = dy;
            dy = t;
        }

        x += dx;
        y += dy;
    }

    return matrix;
}

void spiral_matrix_destroy(spiral_matrix_t* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}