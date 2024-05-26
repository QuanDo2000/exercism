#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_PROTEINS 10
#define CODON_LEN 3

typedef enum {
    INVALID_PROTEIN = -1,
    Methionine,
    Phenylalanine,
    Leucine,
    Serine,
    Tyrosine,
    Cysteine,
    Tryptophan,
    PROTEIN_MAX,
} protein_t;

typedef struct {
    bool valid;
    size_t count;
    protein_t proteins[MAX_PROTEINS];
} proteins_t;

protein_t translate_codon(const char* codon);
proteins_t proteins(const char* const rna);

#endif
