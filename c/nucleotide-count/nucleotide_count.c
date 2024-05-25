#include "nucleotide_count.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char nucleotide_arr[NUCLEOTIDE_MAX] = {'A', 'C', 'G', 'T'};

char* count(const char* dna_strand) {
    char* ans = calloc(MAX_STRING_SIZE, sizeof(char));
    unsigned int* c = calloc(NUCLEOTIDE_MAX, sizeof(unsigned int));
    for (size_t i = 0; i < strlen(dna_strand); i++) {
        char invalid = 1;
        for (int j = 0; j < NUCLEOTIDE_MAX; j++) {
            if (dna_strand[i] == nucleotide_arr[j]) {
                c[j]++;
                invalid = 0;
            }
        }
        if (invalid) {
            ans[0] = '\0';
            free(c);
            return ans;
        }
    }

    for (int i = 0; i < NUCLEOTIDE_MAX; i++) {
        sprintf(ans + strlen(ans), "%c:%d ", nucleotide_arr[i], c[i]);
    }
    ans[strlen(ans) - 1] = '\0';
    free(c);
    return ans;
}