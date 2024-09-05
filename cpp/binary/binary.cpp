#include "binary.h"

#include <cctype>
#include <cmath>

namespace binary {
int convert(string s) {
    int p = s.length() - 1;
    int ans = 0;
    for (char ch : s) {
        if (ch != '0' && ch != '1') return 0;
        if (ch == '1') ans += pow(2, p);
        p--;
    }
    return ans;
}
}  // namespace binary
