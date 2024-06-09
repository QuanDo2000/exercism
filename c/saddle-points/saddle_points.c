#include "saddle_points.h"

#include <stdio.h>
#include <stdlib.h>

saddle_points_t* saddle_points(size_t num_rows, size_t num_cols, uint8_t matrix[num_rows][num_cols]) {
    uint8_t max_rows[num_rows];
    for (size_t i = 0; i < num_rows; i++) {
        uint8_t max = matrix[i][0];
        for (size_t j = 0; j < num_cols; j++) {
            if (max < matrix[i][j]) max = matrix[i][j];
        }
        max_rows[i] = max;
    }

    uint8_t min_cols[num_cols];
    for (size_t j = 0; j < num_cols; j++) {
        uint8_t min = matrix[0][j];
        for (size_t i = 0; i < num_rows; i++) {
            if (min > matrix[i][j]) min = matrix[i][j];
        }
        min_cols[j] = min;
    }

    saddle_points_t* ret = calloc(1, sizeof(saddle_points_t) + sizeof(saddle_point_t) * num_cols * num_rows);
    ret->count = 0;
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_cols; j++) {
            if (max_rows[i] == matrix[i][j] && min_cols[j] == matrix[i][j]) {
                size_t idx = ret->count++;
                ret->points[idx] = (saddle_point_t){
                    .row = i + 1,
                    .column = j + 1,
                };
            }
        }
    }
    return ret;
}

void free_saddle_points(saddle_points_t* points) {
    free(points);
}