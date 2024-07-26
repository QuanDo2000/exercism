#include "rna_transcription.h"

namespace rna_transcription {
char to_rna(char dna) {
    switch (dna) {
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'T':
            return 'A';
        case 'A':
            return 'U';
        default:
            return 0;
    }
}

std::string to_rna(std::string dna) {
    std::string ans = "";

    for (char c : dna) {
        ans += to_rna(c);
    }
    return ans;
}
}  // namespace rna_transcription
