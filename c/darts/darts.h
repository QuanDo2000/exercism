#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>

typedef enum {
    MISSED_TARGET = 0,
    OUTER_CIRCLE = 1,
    MIDDLE_CIRCLE = 5,
    INNER_CIRCLE = 10
} landing_status_t;

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);

#endif
