#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

#define MAX_LEN 20
#define LOOKUP_LEN 13

typedef struct {
    unsigned int arabic;
    char* roman;
    unsigned int len;
} roman_numeral_t;

char* to_roman_numeral(unsigned int number);

#endif
