#include "acronym.h"

#include <cctype>

namespace acronym {
string acronym(string s) {
    string ans = "";
    bool is_first = true;
    for (char ch : s) {
        if (isalpha(ch) && is_first) {
            ans += toupper(ch);
            is_first = false;
        } else if (isspace(ch) || ch == '-') {
            is_first = true;
        }
    }
    return ans;
}
}  // namespace acronym
