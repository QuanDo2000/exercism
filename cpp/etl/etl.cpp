#include "etl.h"

#include <cctype>

namespace etl {
map<char, int> transform(map<int, vector<char>> old) {
    map<char, int> ans;
    for (auto const& [key, val] : old) {
        for (const char& ch : val) {
            ans[tolower(ch)] = key;
        }
    }
    return ans;
}
}  // namespace etl
