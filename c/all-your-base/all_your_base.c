#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {
    if (input_length == 0 || input_base <= 1 || output_base <= 1) return 0;

    int16_t value = 0;
    int16_t pow = 1;
    for (size_t i = input_length; i > 0; i--) {
        if (digits[i - 1] >= input_base || digits[i - 1] < 0) return 0;
        value += digits[i - 1] * pow;
        pow *= input_base;
    }

    size_t len = 0;
    do {
        digits[len++] = value % output_base;
        value /= output_base;
    } while (value > 0);

    for (size_t i = 0; i < len / 2; i++) {
        int8_t t = digits[i];
        digits[i] = digits[len - i - 1];
        digits[len - i - 1] = t;
    }

    return len;
}