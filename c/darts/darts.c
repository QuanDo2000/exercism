#include "darts.h"

#include <math.h>

const float OUTER_RADIUS = 10.0F;
const float MIDDLE_RADIUS = 5.0F;
const float INNER_RADIUS = 1.0F;

static float radius(coordinate_t point) {
    return hypotf(point.x, point.y);
}

uint8_t score(coordinate_t pos) {
    float dist = radius(pos);
    if (dist > OUTER_RADIUS) {
        return MISSED_TARGET;
    } else if (dist > MIDDLE_RADIUS) {
        return OUTER_CIRCLE;
    } else if (dist > INNER_RADIUS) {
        return MIDDLE_CIRCLE;
    } else {
        return INNER_CIRCLE;
    }
}