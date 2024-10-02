#include "rail_fence_cipher.h"

namespace rail_fence_cipher {
string encode(const string& plaintext, int num_rails) {
    vector<vector<char>> rails(num_rails, vector<char>(plaintext.size(), '.'));
    int ri = 0;
    int dir = 1;
    for (size_t i = 0; i < plaintext.size(); i++) {
        rails[ri][i] = plaintext[i];
        if (ri + dir >= num_rails) dir = -1;
        if (ri + dir < 0) dir = 1;
        ri += dir;
    }

    string ans;
    for (size_t i = 0; i < rails.size(); i++) {
        for (size_t j = 0; j < rails[i].size(); j++) {
            if (rails[i][j] != '.') ans += rails[i][j];
        }
    }
    return ans;
}
string decode(const string& ciphertext, int num_rails) {
    vector<vector<char>> rails(num_rails, vector<char>(ciphertext.size(), '.'));
    int ri = 0;
    int dir = 1;
    for (size_t i = 0; i < ciphertext.size(); i++) {
        rails[ri][i] = '?';
        if (ri + dir >= num_rails) dir = -1;
        if (ri + dir < 0) dir = 1;
        ri += dir;
    }

    int idx = 0;
    for (size_t i = 0; i < rails.size(); i++) {
        for (size_t j = 0; j < rails[i].size(); j++) {
            if (rails[i][j] == '?') rails[i][j] = ciphertext[idx++];
        }
    }

    ri = 0;
    dir = 1;
    string ans;
    for (size_t i = 0; i < ciphertext.size(); i++) {
        ans += rails[ri][i];
        if (ri + dir >= num_rails) dir = -1;
        if (ri + dir < 0) dir = 1;
        ri += dir;
    }
    return ans;
}
}  // namespace rail_fence_cipher
