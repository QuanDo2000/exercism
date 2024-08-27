#include "crypto_square.h"

#include <cctype>

namespace crypto_square {
string normalize(string text) {
    string ans = "";
    for (char ch : text) {
        if (isalnum(ch)) ans += tolower(ch);
    }
    return ans;
}

string ciphertext(string normalized_text) {
    size_t len = normalized_text.size();
    size_t r = 0, c = 0;
    while (r * c < len) {
        r++;
        c++;
    }
    if ((r - 1) * c >= len) r--;

    string ans = "";
    for (size_t j = 0; j < c; j++) {
        for (size_t i = 0; i < r; i++) {
            size_t idx = i * c + j;
            if (idx >= len)
                ans += ' ';
            else
                ans += normalized_text[idx];
        }
        if (j != c - 1) ans += ' ';
    }
    return ans;
}

cipher::cipher(string text) {
    this->_text = text;
    this->_cipher = ciphertext(normalize(text));
}

string cipher::normalized_cipher_text() {
    return _cipher;
}
}  // namespace crypto_square
