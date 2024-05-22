#include "sieve.h"

#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t* primes, size_t max_primes) {
    char* arr = calloc(limit + 2, sizeof(char));
    uint32_t count = 0;
    for (uint32_t i = 2; i <= limit && count < max_primes; i++) {
        if (arr[i] != 0) continue;
        for (uint32_t temp = i * 2; temp <= limit; temp += i) {
            arr[temp] = 1;
        }
        primes[count++] = i;
    }
    free(arr);
    return count;
}