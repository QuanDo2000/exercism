#include "rotational_cipher.h"

#include <stdlib.h>
#include <string.h>

static char rot(char ch, int shift) {
    char start_char = 'a';
    if (ch >= 'a' && ch <= 'z') {
        start_char = 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        start_char = 'A';
    } else {
        return ch;
    }
    return ((ch - start_char + shift) % NUM_CHARS_IN_ALPHABET) + start_char;
}

char* rotate(const char* text, int shift_key) {
    size_t len = strlen(text);
    char* ans = calloc(len + 1, sizeof(char));
    for (size_t i = 0; i < len; i++) {
        ans[i] = rot(text[i], shift_key);
    }
    return ans;
}