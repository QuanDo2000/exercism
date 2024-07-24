#include "hamming.h"

#include <stdexcept>

namespace hamming {
int compute(std::string s1, std::string s2) {
    if (s1.size() != s2.size()) throw std::domain_error("Invalid input");

    int count = 0;
    for (size_t i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) count++;
    }
    return count;
}
}  // namespace hamming
