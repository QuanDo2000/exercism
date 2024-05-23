#include "square_root.h"

uint16_t square_root(uint16_t num) {
    for (uint16_t i = 1; i <= num / 2 + 1; i++) {
        if (i * i == num) return i;
    }
    return -1;
}