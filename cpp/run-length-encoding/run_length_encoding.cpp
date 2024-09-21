#include "run_length_encoding.h"

#include <cctype>

namespace run_length_encoding {
string encode(string input) {
    if (input.size() == 0) return "";

    string ans = "";
    char curr = input.at(0);
    int count = 0;
    for (char ch : input) {
        if (ch != curr) {
            if (count != 1)
                ans += to_string(count) + curr;
            else
                ans += curr;
            count = 1;
        } else {
            count++;
        }
        curr = ch;
    }
    if (count != 1)
        ans += to_string(count) + curr;
    else
        ans += curr;
    return ans;
}

string decode(string input) {
    if (input.size() == 0) return "";

    string ans = "";
    string tmp = "";
    for (char ch : input) {
        if (isdigit(ch)) {
            tmp += ch;
        } else {
            if (tmp != "") {
                for (int i = 0; i < stoi(tmp); i++) {
                    ans += ch;
                }
                tmp = "";
            } else {
                ans += ch;
            }
        }
    }
    return ans;
}
}  // namespace run_length_encoding
