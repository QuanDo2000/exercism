#include "word_count.h"

#include <ctype.h>
#include <string.h>

static int is_word(char ch) {
    return isalnum(ch) || ch == '\'';
}

static void add_word(word_count_word_t* words, int* len, char* word) {
    for (int i = 0; i < *len; i++) {
        if (strcmp(words[i].text, word) == 0) {
            words[i].count++;
            return;
        }
    }

    strcpy(words[*len].text, word);
    words[*len].count++;
    (*len)++;
    return;
}

int count_words(const char* sentence, word_count_word_t* words) {
    char word[MAX_WORD_LENGTH + 1];
    memset(word, 0, sizeof(word));

    int i = 0, len = 0;
    for (size_t idx = 0; idx <= strlen(sentence); idx++) {
        char ch = sentence[idx];
        if (is_word(ch)) {
            if (i >= MAX_WORD_LENGTH) return EXCESSIVE_LENGTH_WORD;
            if (i != 0 || ch != '\'') word[i++] = tolower(ch);
        } else {
            if (i > 0 && word[i - 1] == '\'') i--;
            word[i] = '\0';
            if (len >= MAX_WORDS) return EXCESSIVE_NUMBER_OF_WORDS;
            if (i > 0) add_word(words, &len, word);
            memset(word, 0, sizeof(word));
            i = 0;
        }
    }
    return len;
}