#include "anagram.h"

#include <stdio.h>
#include <stdlib.h>

static char is_lower(const char ch) {
    return (ch >= 'a' && ch <= 'z');
}

static char is_upper(const char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

static void count_word(const char* word, int* count) {
    for (; (*word) != '\0'; word++) {
        char ch = *word;
        if (is_lower(ch)) {
            count[ch - 'a']++;
        } else if (is_upper(ch)) {
            count[ch - 'A']++;
        }
    }
}

static char is_count_equal(int* count1, int* count2) {
    for (int i = 0; i < ALPHABET_LEN; i++) {
        if (count1[i] != count2[i]) return 0;
    }
    return 1;
}

static char is_word_equal(const char* word1, const char* word2) {
    const char *w1 = word1, *w2 = word2;
    for (; (*w1) != '\0' && (*w2) != '\0'; w1++, w2++) {
        char ch1 = *w1;
        if (is_lower(ch1)) ch1 -= 'a';
        if (is_upper(ch1)) ch1 -= 'A';
        char ch2 = *w2;
        if (is_lower(ch2)) ch2 -= 'a';
        if (is_upper(ch2)) ch2 -= 'A';
        if (ch1 != ch2) return 0;
    }
    if (*w1 != *w2) return 0;
    return 1;
}

static void check_anagram(struct candidate* candidate, const char* word) {
    int* count = calloc(ALPHABET_LEN, sizeof(int));
    count_word(word, count);

    int* new_count = calloc(ALPHABET_LEN, sizeof(int));
    count_word(candidate->word, new_count);

    if (is_count_equal(count, new_count) && !is_word_equal(word, candidate->word)) {
        candidate->is_anagram = IS_ANAGRAM;
    } else {
        candidate->is_anagram = NOT_ANAGRAM;
    }

    free(count);
    free(new_count);
}

void find_anagrams(const char* subject, struct candidates* candidates) {
    for (size_t i = 0; i < candidates->count; i++) {
        struct candidate* candidate = candidates->candidate + i;
        if (!candidate) continue;
        check_anagram(candidate, subject);
    }
}