#include "scrabble_score.h"

namespace scrabble_score {
const int ALPHABET_COUNT = 26;
const int val[ALPHABET_COUNT] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5,
    1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4,
    4, 8, 4, 10};

int score(string word) {
    int s = 0;
    for (char ch : word) {
        if (isalpha(ch)) s += val[tolower(ch) - 'a'];
    }
    return s;
}
}  // namespace scrabble_score
