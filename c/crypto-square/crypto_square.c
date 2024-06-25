#include "crypto_square.h"

#include <stdlib.h>
#include <string.h>

static int normalize(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    if (ch >= 'a' && ch <= 'z') return ch;
    if (ch >= '0' && ch <= '9') return ch;
    return 0;
}

static char* normalize_input(const char* input) {
    const size_t len = strlen(input);
    char* normalized = calloc(len + 1, sizeof(char));

    size_t idx = 0;
    for (size_t i = 0; i < len; i++) {
        char ch = normalize(input[i]);
        if (ch != 0) normalized[idx++] = ch;
    }
    return normalized;
}

char* ciphertext(const char* input) {
    char* normalized_input = normalize_input(input);

    const int len = strlen(normalized_input);
    int r = 0, c = 0;
    while (r * c < len) {
        r++;
        c++;
    }
    if ((r - 1) * c >= len) r--;

    char square[r][c + 1];
    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            square[i][j] = ' ';
            if (idx < len) {
                square[i][j] = normalized_input[idx++];
            }
        }
        square[i][c] = '\0';
    }
    free(normalized_input);

    char* ans = calloc((r * (c + 1)) + 1, sizeof(char));
    idx = 0;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (square[i][j] != '\0') ans[idx++] = square[i][j];
        }
        if (j != c - 1) ans[idx++] = ' ';
    }
    return ans;
}