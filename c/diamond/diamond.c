#include "diamond.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** make_diamond(const char letter) {
    if (letter < 'A' || letter > 'Z') return NULL;

    int line_len = (letter - 'A') * 2 + 1;
    int mid = line_len / 2;

    char** diamond = calloc(line_len, sizeof(char*));
    for (int i = 0; i < line_len; i++) {
        int idx = i < mid ? i : (line_len - 1) - i;
        char ch = 'A' + idx;
        int right = mid + idx;
        int left = mid - idx;
        diamond[i] = calloc(line_len + 1, sizeof(char));
        for (int j = 0; j < line_len; j++) {
            diamond[i][j] = (j == right || j == left) ? ch : ' ';
        }
    }
    return diamond;
}

void free_diamond(char** diamond) {
    size_t len = strlen(diamond[0]);
    for (size_t i = 0; i < len; i++) {
        free(diamond[i]);
    }
    free(diamond);
}