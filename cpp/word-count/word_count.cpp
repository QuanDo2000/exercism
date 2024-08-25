#include "word_count.h"

#include <algorithm>
#include <cctype>
#include <regex>

namespace word_count {
constexpr const char* REGEX = "\\w+(?:'\\w+)?";

map<string, int> words(string s) {
    map<string, int> ans;
    regex re(REGEX);

    for (sregex_token_iterator it(s.begin(), s.end(), re), end; it != end; it++) {
        string word(*it);
        transform(word.cbegin(), word.cend(), word.begin(), ::tolower);
        ans[word]++;
    }
    return ans;
}
}  // namespace word_count
