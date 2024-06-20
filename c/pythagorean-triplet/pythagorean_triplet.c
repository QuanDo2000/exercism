#include "pythagorean_triplet.h"

#include <stdlib.h>

triplets_t* triplets_with_sum(int sum) {
    triplets_t* triplets = calloc(1, sizeof(triplets_t) + MAX_COUNT * sizeof(triplet_t));
    triplets->count = 0;

    for (int a = 1; a <= sum; a++) {
        for (int b = a + 1; b <= sum; b++) {
            int c = sum - a - b;
            if (c <= b || c * c != a * a + b * b) continue;
            triplets->triplets[triplets->count++] = (triplet_t){
                .a = a,
                .b = b,
                .c = c,
            };
        }
    }
    return triplets;
}

void free_triplets(triplets_t* triplets) {
    free(triplets);
}