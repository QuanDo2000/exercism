#include "series.h"

#include <stdexcept>

namespace series {
vector<string> slice(string s, size_t l) {
    if (l > s.size() || l <= 0) throw domain_error("invalid slice length");

    vector<string> ans;
    for (size_t i = 0; i <= s.size() - l; i++) {
        ans.emplace_back(s.substr(i, l));
    }
    return ans;
}
}  // namespace series
