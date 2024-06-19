#include "minesweeper.h"

#include <stdlib.h>
#include <string.h>

static char process_square(const char** minefield, int r, int c, const size_t rows, const size_t cols) {
    if (minefield[r][c] == '*') return '*';
    int count = 0;
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i < 0 || i >= (int)rows || j < 0 || j >= (int)cols) continue;
            if (minefield[i][j] == '*') count++;
        }
    }
    if (count == 0) return ' ';
    return count + '0';
}

char** annotate(const char** minefield, const size_t rows) {
    if (rows == 0) return NULL;

    const size_t cols = strlen(minefield[0]);

    char** ans = calloc(rows + 1, sizeof(char*));
    for (size_t i = 0; i < rows; i++) {
        ans[i] = calloc(cols + 1, sizeof(char));
        for (size_t j = 0; j < cols; j++) {
            ans[i][j] = process_square(minefield, i, j, rows, cols);
        }
    }
    return ans;
}

void free_annotation(char** annotation) {
    for (int idx = 0; annotation[idx] != NULL; idx++) {
        free(annotation[idx]);
    }
    free(annotation);
}