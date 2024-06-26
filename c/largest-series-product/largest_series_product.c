#include "largest_series_product.h"

#include <stdio.h>
#include <string.h>

int64_t largest_series_product(char* digits, size_t span) {
    const size_t len = strlen(digits);
    if (span > len || len < 1 || span <= 0) return -1;

    int64_t max = 0;
    size_t start = 0, end = span;
    for (end = span; end <= len; start++, end++) {
        int64_t product = 1;
        for (size_t i = start; i < end; i++) {
            if (digits[i] < '0' || digits[i] > '9') return -1;
            product *= digits[i] - '0';
        }
        if (product > max) max = product;
    }

    return max;
}