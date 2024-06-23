#include "pig_latin.h"

#include <stdlib.h>
#include <string.h>

static char* SUFFIX = "ay";
static char* VOWELS = "aeiou";

static int is_vowel(char ch) {
    for (size_t i = 0; i < strlen(VOWELS); i++) {
        if (ch == VOWELS[i]) return 1;
    }
    return 0;
}

static int is_consonant(char ch) {
    return (!is_vowel(ch) && ch >= 'a' && ch <= 'z');
}

static size_t get_consonant_prefix(const char* phrase) {
    const size_t len = strlen(phrase);
    size_t prefix_len = 0;
    while ((is_consonant(phrase[prefix_len]) &&
            (prefix_len == 0 ||
             (prefix_len > 0 && phrase[prefix_len] != 'y'))) &&
           prefix_len < len) prefix_len++;
    return prefix_len;
}

static int is_rule(const char* phrase) {
    if (is_vowel(phrase[0]) || strncmp(phrase, "xr", 2) == 0 || strncmp(phrase, "yt", 2) == 0) return 1;

    const size_t len = get_consonant_prefix(phrase);
    if (len == 0) return 1;

    if (phrase[len] == 'u' && phrase[len - 1] == 'q') return 3;
    if (phrase[len - 1] == 'y' && len >= 2) return 4;
    return 2;
}

char* translate(const char* phrase) {
    const size_t len = strlen(phrase);
    char* ans = calloc(len + MAX_EXTRA, sizeof(char));

    char* suffix = calloc(MAX_SUFFIX_LEN, sizeof(char));
    size_t idx = 0;
    for (size_t i = 0; i < len; i++) {
        int is_start = 0, is_end = 0;
        if (i == 0 || phrase[i - 1] == ' ') is_start = 1;
        if (i + 1 == len || phrase[i + 1] == ' ') is_end = 1;

        if (is_start) {
            switch (is_rule(&phrase[i])) {
                case 1:
                    ans[idx++] = phrase[i];
                    break;
                case 2:
                    strncpy(suffix, &phrase[i], get_consonant_prefix(&phrase[i]));
                    i += strlen(suffix) - 1;
                    break;
                case 3:
                    strncpy(suffix, &phrase[i], get_consonant_prefix(&phrase[i]) - 1);
                    strcat(suffix, "qu");
                    i += strlen(suffix) - 1;
                    break;
                case 4:
                    strncpy(suffix, &phrase[i], get_consonant_prefix(&phrase[i]) - 1);
                    i += strlen(suffix) - 1;
                default:
                    break;
            }
            strcat(suffix, SUFFIX);
            is_start = 0;
        } else if (is_end) {
            ans[idx++] = phrase[i];
            strcat(ans, suffix);
            idx += strlen(suffix);
            memset(suffix, 0, sizeof(char) * MAX_SUFFIX_LEN);
            is_end = 0;
        } else if (!is_start && !is_end) {
            ans[idx++] = phrase[i];
        }
    }
    free(suffix);
    return ans;
}