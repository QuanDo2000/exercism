#include "trinary.h"

#include <cctype>

namespace trinary {
int to_decimal(string t) {
    int ans = 0;
    int place = 1;
    for (int i = t.length() - 1; i >= 0; i--) {
        char ch = t.at(i);
        if (!isdigit(ch)) return 0;
        int num = ch - '0';
        ans += num * place;
        place *= 3;
    }
    return ans;
}
}  // namespace trinary
