#include "roman_numerals.h"

#include <stdlib.h>
#include <string.h>

static const roman_numeral_t lookup[LOOKUP_LEN] = {
    {1000, "M", 1},
    {900, "CM", 2},
    {500, "D", 1},
    {400, "CD", 2},
    {100, "C", 1},
    {90, "XC", 2},
    {50, "L", 1},
    {40, "XL", 2},
    {10, "X", 1},
    {9, "IX", 2},
    {5, "V", 1},
    {4, "IV", 2},
    {1, "I", 1},
};

char* to_roman_numeral(unsigned int number) {
    char* res = calloc(MAX_LEN, sizeof(char));
    if (!res) return NULL;

    int len = 0;
    for (int i = 0; i < LOOKUP_LEN; i++) {
        roman_numeral_t numeral = lookup[i];
        while (number >= numeral.arabic) {
            memcpy(res + len, numeral.roman, numeral.len);
            len += numeral.len;
            number -= numeral.arabic;
        }
    }
    return res;
}