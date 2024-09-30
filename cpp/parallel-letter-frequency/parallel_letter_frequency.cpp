#include "parallel_letter_frequency.h"

namespace parallel_letter_frequency {
map<char, int> combine(map<char, int> freq1, map<char, int> freq2) {
    map<char, int> freq;
    freq.merge(freq1);
    for (auto &[ch, count] : freq2) {
        freq[ch] += count;
    }
    return freq;
}

map<char, int> count(string_view text) {
    map<char, int> freq;
    for (auto ch : text) {
        if (isalpha(ch)) {
            char l = tolower(ch);
            freq[l]++;
        }
    }
    return freq;
}

map<char, int> frequency(vector<string_view> texts) {
    return transform_reduce(execution::par, texts.cbegin(), texts.cend(), map<char, int>(), combine, count);
}
}  // namespace parallel_letter_frequency
