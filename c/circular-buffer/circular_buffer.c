#include "circular_buffer.h"

#include <errno.h>
#include <stdlib.h>

static int buffer_full(circular_buffer_t* buffer) {
    return (buffer->len == buffer->capacity);
}

circular_buffer_t* new_circular_buffer(int capacity) {
    circular_buffer_t* buffer = calloc(1, sizeof(circular_buffer_t));
    buffer->capacity = capacity;
    clear_buffer(buffer);
    return buffer;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value) {
    if (buffer_full(buffer)) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
    int idx = (buffer->start + (buffer->len++)) % buffer->capacity;
    buffer->values[idx] = value;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value) {
    if (buffer_full(buffer)) {
        buffer->start++;
        buffer->start %= buffer->capacity;
        buffer->len--;
    }
    return write(buffer, value);
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value) {
    if (buffer->len == EXIT_SUCCESS) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    buffer_value_t ans = buffer->values[buffer->start++];
    buffer->start %= buffer->capacity;
    buffer->len--;
    *value = ans;
    return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t* buffer) {
    free(buffer);
}

void clear_buffer(circular_buffer_t* buffer) {
    buffer->start = 0;
    buffer->len = 0;
}