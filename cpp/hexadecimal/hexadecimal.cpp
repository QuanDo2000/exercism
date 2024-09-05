#include "hexadecimal.h"

#include <cctype>
#include <cmath>

namespace hexadecimal {
long long convert(string s) {
    long long ans = 0;
    int p = s.length() - 1;
    for (char ch : s) {
        int num = 0;
        if (isdigit(ch))
            num = ch - '0';
        else if (ch >= 'a' && ch <= 'f')
            num = 10 + ch - 'a';
        else
            return 0;
        ans += pow(16, p) * num;
        p--;
    }
    return ans;
}
}  // namespace hexadecimal
