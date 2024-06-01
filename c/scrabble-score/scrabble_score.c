#include "scrabble_score.h"

const int val[ALPHABET_COUNT] = {
    1, 3, 3, 2,
    1, 4, 2, 4,
    1, 8, 5, 1,
    3, 1, 1, 3,
    10, 1, 1, 1,
    1, 4, 4, 8,
    4, 10};

unsigned int score(const char* word) {
    unsigned int ans = 0;
    for (; (*word) != '\0'; word++) {
        char ch = *word;
        if (ch >= 'a' && ch <= 'z') {
            ans += val[ch - 'a'];
        } else if (ch >= 'A' && ch <= 'Z') {
            ans += val[ch - 'A'];
        }
    }
    return ans;
}