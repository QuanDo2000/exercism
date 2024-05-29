#include "nth_prime.h"

static char checkPrime(uint32_t n) {
    for (uint32_t i = 2; i <= (n / 2) + 1; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

uint32_t nth(uint32_t n) {
    if (n == 0) return 0;

    uint32_t count = 1, p = 2;
    while (count < n) {
        if (checkPrime(p)) count++;
        if (count == n) return p;
        p++;
    }
    return p;
}