#include "etl.h"

#include <stdlib.h>

static int comp(const void* a, const void* b) {
    return ((new_map*)a)->key - ((new_map*)b)->key;
}

int convert(const legacy_map* input, const size_t input_len, new_map** output) {
    *output = malloc(sizeof(new_map) * MAX_SIZE);

    int len = 0;
    for (size_t i = 0; i < input_len; i++) {
        int value = input[i].value;
        const char* keys = input[i].keys;
        for (int j = 0; keys[j] != '\0'; j++) {
            (*output)[len].key = keys[j] - 'A' + 'a';
            (*output)[len].value = value;
            len++;
        }
    }
    qsort(*output, len, sizeof(new_map), comp);
    return len;
}