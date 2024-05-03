#include "rna_transcription.h"

#include <stdlib.h>
#include <string.h>

static char get_complement(const char dna) {
    switch (dna) {
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'A':
            return 'U';
        default:
            return dna;
    }
}

char* to_rna(const char* dna) {
    size_t dna_len = strlen(dna);
    char* rna = malloc(dna_len + 1);

    unsigned int i = 0;
    for (i = 0; i < dna_len; i++, dna++) {
        rna[i] = get_complement(*dna);
    }
    rna[i] = '\0';
    return rna;
}