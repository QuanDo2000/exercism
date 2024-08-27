#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>

using namespace std;

namespace crypto_square {
class cipher {
   private:
    string _cipher;
    string _text;

   public:
    cipher(string text);
    string normalized_cipher_text();
};
}  // namespace crypto_square

#endif  // CRYPTO_SQUARE_H