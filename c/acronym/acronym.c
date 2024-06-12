#include "acronym.h"

#include <stdlib.h>
#include <string.h>

char* abbreviate(const char* phrase) {
    if (!phrase) return NULL;
    size_t phrase_len = strlen(phrase);
    if (phrase_len == 0) return NULL;

    size_t len = 0;
    char* acronym = calloc(phrase_len, sizeof(char));

    acronym[len++] = phrase[0];
    for (size_t i = 1; i < phrase_len; i++) {
        char prev = phrase[i - 1];
        char curr = phrase[i];
        if (prev == ' ' || prev == '-' || prev == '_') {
            if (curr >= 'a' && curr <= 'z') {
                curr = curr - 'a' + 'A';
            }
            if (curr >= 'A' && curr <= 'Z') {
                acronym[len++] = curr;
            }
        }
    }
    return acronym;
}