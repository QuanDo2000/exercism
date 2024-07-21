#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <string>

const int NUM_ALPHABETS = 26;

namespace pangram {
bool is_pangram(std::string s);
}  // namespace pangram

#endif  // PANGRAM_H