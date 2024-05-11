#include "resistor_color_trio.h"

#include <stdio.h>

resistor_value_t color_code(resistor_band_t* colors) {
    uint16_t value = colors[0] * 10 + colors[1];
    resistor_unit_t unit = colors[2] / 3;

    for (unsigned int i = 0; i < (colors[2] % 3); i++) {
        value *= 10;
    }

    if (value > 0 && value % 1000 == 0) {
        value /= 1000;
        unit++;
    }

    resistor_value_t ans = {value, unit};
    return ans;
}