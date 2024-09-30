#if !defined(PARALLEL_LETTER_FREQUENCY_H)
#define PARALLEL_LETTER_FREQUENCY_H

#include <algorithm>
#include <cctype>
#include <execution>
#include <map>
#include <string_view>
#include <vector>

using namespace std;

namespace parallel_letter_frequency {
map<char, int> frequency(vector<string_view> texts);
}

#endif
