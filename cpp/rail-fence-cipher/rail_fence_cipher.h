#pragma once

#include <string>
#include <vector>

using namespace std;

namespace rail_fence_cipher {
string encode(const string& plaintext, int num_rails);
string decode(const string& ciphertext, int num_rails);
}  // namespace rail_fence_cipher
