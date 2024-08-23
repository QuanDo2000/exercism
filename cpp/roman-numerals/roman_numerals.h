#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H

#include <string>

using namespace std;

namespace roman_numerals {
struct numerals {
    int arabic;
    string roman;
};
string convert(int num);
}  // namespace roman_numerals

#endif  // ROMAN_NUMERALS_H