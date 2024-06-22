#include "rail_fence_cipher.h"

#include <stdlib.h>
#include <string.h>

char* encode(char* text, size_t rails) {
    const size_t len = strlen(text);
    const size_t MAX_CHARS = len + 1;

    char** fences = calloc(rails, sizeof(char*));
    for (size_t i = 0; i < rails; i++) {
        fences[i] = calloc(MAX_CHARS, sizeof(char));
    }

    size_t f_idx = 0;
    int dir = 1;
    for (size_t i = 0; i < len; i++) {
        char ch = text[i];
        strncat(fences[f_idx], &ch, 1);
        if (f_idx == rails - 1 || (f_idx == 0 && i != 0)) dir *= -1;
        f_idx += dir;
    }

    char* ans = calloc(MAX_CHARS, sizeof(char));
    for (size_t i = 0; i < rails; i++) {
        strncat(ans, fences[i], strlen(fences[i]));
        free(fences[i]);
    }
    free(fences);
    return ans;
}

char* decode(char* ctext, size_t rails) {
    int flen[rails];
    for (size_t i = 0; i < rails; i++) {
        flen[i] = 0;
    }

    const size_t len = strlen(ctext);
    size_t f_idx = 0;
    int dir = 1;
    for (size_t i = 0; i < len; i++) {
        flen[f_idx]++;
        if (f_idx == rails - 1 || (f_idx == 0 && i != 0)) dir *= -1;
        f_idx += dir;
    }

    for (size_t i = 0; i < rails; i++) {
        if (i > 0) flen[i] += flen[i - 1];
    }
    for (size_t i = rails; i > 0; i--) {
        if (i == 1) {
            flen[i - 1] = 0;
        } else {
            flen[i - 1] = flen[i - 2];
        }
    }

    const size_t MAX_CHARS = len + 1;
    char* ans = calloc(MAX_CHARS, sizeof(char));
    size_t idx = 0;

    f_idx = 0;
    dir = 1;
    for (size_t i = 0; i < len; i++) {
        char ch = ctext[flen[f_idx]++];
        ans[idx++] = ch;
        if (f_idx == rails - 1 || (f_idx == 0 && i != 0)) dir *= -1;
        f_idx += dir;
    }
    return ans;
}