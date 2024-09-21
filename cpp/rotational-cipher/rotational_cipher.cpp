#include "rotational_cipher.h"

#include <cctype>

namespace rotational_cipher {
string rotate(string s, int num) {
    if (num == 0) return s;

    string ans = "";
    for (char ch : s) {
        if (isalpha(ch)) {
            char n = ch;
            if (islower(ch)) {
                n = ch - 'a';
                n = (n + num) % 26 + 'a';
            } else if (isupper(ch)) {
                n = ch - 'A';
                n = (n + num) % 26 + 'A';
            }
            ans += n;
        } else {
            ans += ch;
        }
    }
    return ans;
}
}  // namespace rotational_cipher
