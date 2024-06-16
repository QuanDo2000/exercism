#ifndef ETL_H
#define ETL_H

#include <stddef.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    const char *keys;
} legacy_map;

typedef struct {
    char key;
    int value;
} new_map;

int convert(const legacy_map *input, const size_t input_len, new_map **output);

#endif
