#include "luhn.h"

#include <cctype>

namespace luhn {
string process_input(string s) {
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        char ch = s[i];
        if (isspace(ch)) continue;
        if (!isdigit(ch)) return "";
        ans += ch;
    }
    return ans;
}

bool valid(string s) {
    string nums = process_input(s);
    if (nums.size() <= 1) return false;

    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        char ch = nums[i];
        int v = ch - '0';
        if (i % 2 == 1) {
            v *= 2;
            if (v > 9) v -= 9;
        }
        sum += v;
    }
    return sum % 10 == 0;
}
}  // namespace luhn
