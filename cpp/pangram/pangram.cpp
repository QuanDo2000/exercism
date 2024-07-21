#include "pangram.h"

#include <bitset>

namespace pangram {
bool is_pangram(std::string s) {
    std::bitset<NUM_ALPHABETS> letters;

    for (const auto c : s) {
        if (std::isalpha(c)) letters.set(std::tolower(c) - 'a');
    }

    return letters.all();
}
}  // namespace pangram
