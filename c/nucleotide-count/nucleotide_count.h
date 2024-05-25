#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#define MAX_STRING_SIZE 100

typedef enum {
    NUCLEOTIDE_A,
    NUCLEOTIDE_C,
    NUCLEOTIDE_G,
    NUCLEOTIDE_T,
    NUCLEOTIDE_MAX,
} nucleotide_t;

char *
count(const char *dna_strand);

#endif
