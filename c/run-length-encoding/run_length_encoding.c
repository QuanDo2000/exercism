#include "run_length_encoding.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode(const char* text) {
    const size_t len = strlen(text);

    char* ans = calloc(len + 1, sizeof(char));
    if (len <= 1) {
        memcpy(ans, text, len + 1);
        return ans;
    }

    int idx = 0;
    int count = 1;
    char prev = text[0];
    for (size_t i = 1; i <= len; i++) {
        if (text[i] != prev) {
            if (count > 1) idx += sprintf(&ans[idx], "%d", count);
            idx += sprintf(&ans[idx], "%c", prev);
            count = 1;
        } else {
            count++;
        }
        prev = text[i];
    }
    return ans;
}

char* decode(const char* data) {
    const size_t len = strlen(data);
    char* ans = calloc(MAX_LEN, sizeof(char));

    int idx = 0;
    size_t prev = 0;
    int count;
    for (size_t i = 0; i < len; i++) {
        if (data[i] < '0' || data[i] > '9') {
            count = atoi(&data[prev]);
            if (count == 0 || i == prev) count = 1;
            for (int j = 0; j < count; j++) {
                ans[idx++] = data[i];
            }
            prev = i + 1;
        }
    }
    return ans;
}