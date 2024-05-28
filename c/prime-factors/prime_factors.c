#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[MAXFACTORS]) {
    size_t len = 0;
    for (uint64_t factor = 2; factor <= n; factor++) {
        while (n % factor == 0 && n > 0) {
            n /= factor;
            factors[len++] = factor;
        }
        if (n <= 0) break;
    }
    return len;
}