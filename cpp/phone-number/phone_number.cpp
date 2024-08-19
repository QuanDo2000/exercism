#include "phone_number.h"

#include <cctype>
#include <stdexcept>

namespace phone_number {
phone_number::phone_number(string num) {
    string digits = "";
    for (auto ch : num) {
        if (isdigit(ch)) digits += ch;
    }

    string ans;
    if (digits.size() == 11 && digits[0] == '1') {
        ans = digits.substr(1);
    } else if (digits.size() == 10) {
        ans = digits;
    } else {
        throw domain_error("invalid number of digits");
    }
    if (ans[0] == '0' || ans[0] == '1' || ans[3] == '0' || ans[3] == '1')
        throw domain_error("invalid first digit");

    this->n = ans;
}

string phone_number::number() {
    return this->n;
}
}  // namespace phone_number
