#include "protein_translation.h"

#include <string.h>

static const char codon_arr[PROTEIN_MAX + 1][PROTEIN_MAX][CODON_LEN + 1] = {
    {"AUG"},
    {"UUU", "UUC"},
    {"UUA", "UUG"},
    {"UCU", "UCC", "UCA", "UCG"},
    {"UAU", "UAC"},
    {"UGU", "UGC"},
    {"UGG"},
    {"UAA", "UAG", "UGA"},
};

static bool str_equal(const char* a, const char* b) {
    return (strcmp(a, b) == 0);
}

protein_t translate_codon(const char* codon) {
    if (strlen(codon) != 3) return INVALID_PROTEIN;
    for (int i = 0; i < PROTEIN_MAX + 1; i++) {
        for (int j = 0; j < PROTEIN_MAX; j++) {
            if (str_equal(codon, codon_arr[i][j])) {
                return i;
            }
        }
    }
    return INVALID_PROTEIN;
}

proteins_t proteins(const char* const rna) {
    proteins_t ans;
    ans.valid = true;
    ans.count = 0;
    for (size_t i = 0; i < strlen(rna); i += CODON_LEN) {
        char codon[CODON_LEN + 1];
        strncpy(codon, &rna[i], CODON_LEN);
        protein_t prot = translate_codon(codon);
        if (prot == INVALID_PROTEIN) {
            ans.valid = false;
            return ans;
        }
        if (prot == PROTEIN_MAX) {
            return ans;
        }
        ans.proteins[ans.count++] = prot;
    }
    return ans;
}