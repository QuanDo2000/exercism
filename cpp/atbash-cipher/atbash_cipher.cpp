#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher {
string encode(string s) {
    string ans = "";
    for (size_t i = 0; i < s.length(); i++) {
        char ch = s.at(i);
        if (isalpha(ch)) {
            ans += 'z' - tolower(ch) + 'a';
        } else if (isdigit(ch)) {
            ans += ch;
        }

        if (ans.length() % 6 == 5) {
            ans += ' ';
        }
    }

    if (ans.length() > 1 && ans[ans.length() - 1] == ' ') {
        ans.pop_back();
    }
    return ans;
}

string decode(string s) {
    string ans = "";
    for (auto ch : s) {
        if (isalpha(ch)) {
            ans += 'z' - tolower(ch) + 'a';
        } else if (isdigit(ch)) {
            ans += ch;
        }
    }
    return ans;
}
}  // namespace atbash_cipher
