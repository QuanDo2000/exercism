#include "grains.h"

uint64_t square(uint8_t index) {
    if (index <= 0 || index > 64) {
        return 0;
    }

    uint64_t ans = 1;
    for (uint8_t i = 0; i < index - 1; i++) {
        ans *= 2;
    }
    return ans;
}

uint64_t total() {
    uint64_t ans = 0;
    for (int i = 1; i <= 64; i++) {
        ans += square(i);
    }
    return ans;
}