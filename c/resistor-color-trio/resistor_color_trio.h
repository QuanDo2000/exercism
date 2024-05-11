#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

#define COLORS \
    BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

#define METRICS \
    OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS

typedef enum RESISTOR_BANDS { COLORS } resistor_band_t;
typedef enum REDISTOR_UNITS { METRICS } resistor_unit_t;

typedef struct {
    uint16_t value;
    resistor_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t* colors);

#endif
