#include "roman_numerals.h"

#include <vector>

namespace roman_numerals {
const vector<numerals> LOOKUP = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

string convert(int num) {
    string ans = "";

    for (const auto& numeral : LOOKUP) {
        while (num >= numeral.arabic) {
            ans += numeral.roman;
            num -= numeral.arabic;
        }
    }
    return ans;
}
}  // namespace roman_numerals
