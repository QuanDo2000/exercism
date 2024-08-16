#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

using namespace std;

namespace atbash_cipher {
string encode(string s);
string decode(string s);
}  // namespace atbash_cipher

#endif  // ATBASH_CIPHER_H