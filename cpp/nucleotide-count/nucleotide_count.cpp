#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {
std::map<char, int> count(std::string dna) {
    std::map<char, int> c = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (auto ch : dna) {
        if (c.count(ch) == 0) throw std::invalid_argument("Unknown nucleotide");
        c[ch]++;
    }
    return c;
}
}  // namespace nucleotide_count
