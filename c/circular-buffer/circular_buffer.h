#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>

#define MAX_CAPACITY 100

typedef int buffer_value_t;

typedef struct {
    int capacity, len;
    buffer_value_t values[MAX_CAPACITY];
    int start;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer(int capacity);
int16_t write(circular_buffer_t* buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value);
int16_t read(circular_buffer_t* buffer, buffer_value_t* value);
void delete_buffer(circular_buffer_t* buffer);
void clear_buffer(circular_buffer_t* buffer);

#endif
