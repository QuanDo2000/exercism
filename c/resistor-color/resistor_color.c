#include "resistor_color.h"

static resistor_band_t color_array[10] = {COLORS};

uint16_t color_code(resistor_band_t color) {
    return color;
}

resistor_band_t *colors(void) {
    return color_array;
}