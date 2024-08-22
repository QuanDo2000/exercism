#include "food_chain.h"

namespace food_chain {
const string FIRST_VERSE = "I know an old lady who swallowed a ";
const vector<string> ANIMALS = {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
const vector<string> SUB_VERSES = {
    "I don't know why she swallowed the fly. Perhaps she'll die.",
    "It wriggled and jiggled and tickled inside her.",
    "How absurd to swallow a bird!",
    "Imagine that, to swallow a cat!",
    "What a hog, to swallow a dog!",
    "Just opened her throat and swallowed a goat!",
    "I don't know how she swallowed a cow!",
    "She's dead, of course!",
};

string verse(size_t num) {
    string ans = FIRST_VERSE + ANIMALS[num - 1] + ".\n";
    if (num > 1 && num < ANIMALS.size()) {
        ans += SUB_VERSES[num - 1] + "\n";
    }
    while (num < ANIMALS.size() && num > 1) {
        ans += "She swallowed the " + ANIMALS[num - 1] + " to catch the " + ANIMALS[num - 2];
        if (num - 2 == 1) {
            ans += " that wriggled and jiggled and tickled inside her.\n";
        } else {
            ans += ".\n";
        }
        num -= 1;
    }
    ans += SUB_VERSES[num - 1] + "\n";
    return ans;
}
string verses(size_t start_idx, size_t end_idx) {
    string ans = "";
    for (size_t i = start_idx; i <= end_idx; i++) {
        ans += verse(i) + "\n";
    }
    return ans;
}
string sing() {
    return verses(1, 8);
}
}  // namespace food_chain
