#include "isbn_verifier.h"

#include <cctype>

namespace isbn_verifier {
string process_isbn(string isbn) {
    string ans = "";
    for (char ch : isbn) {
        if (isalnum(ch)) ans += ch;
    }
    return ans;
}

bool is_valid(string isbn) {
    string parsed_isbn = process_isbn(isbn);
    if (parsed_isbn.length() != 10) return false;

    int pos = 10;
    int result = 0;
    for (char digit : parsed_isbn) {
        if (pos != 1) {
            if (isdigit(digit))
                result += (digit - '0') * pos;
            else
                return false;
        }
        if (pos == 1) {
            if (isdigit(digit))
                result += digit - '0';
            else if (digit == 'X')
                result += 10;
            else
                return false;
        }
        pos--;
    }
    return (result % 11) == 0;
}
}  // namespace isbn_verifier