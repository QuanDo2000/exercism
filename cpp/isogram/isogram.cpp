#include "isogram.h"

#include <cctype>
#include <vector>

namespace isogram {
bool is_isogram(string s) {
    vector<bool> has(26, false);
    for (char ch : s) {
        char c = tolower(ch);
        if (c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            if (has[idx]) return false;
            has[idx] = true;
        }
    }
    return true;
}
}  // namespace isogram
