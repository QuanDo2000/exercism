#include "bob.h"

#include <cctype>

namespace bob {
string hey(string s) {
    bool question = false;
    bool upperCase = false;
    bool lowerCase = false;
    bool space = true;

    for (char ch : s) {
        if (islower(ch)) lowerCase = true;
        if (isupper(ch)) upperCase = true;
        if (!isspace(ch)) {
            question = false;
            space = false;
        }
        if (ch == '?') question = true;
    }

    bool yell = upperCase && !lowerCase;
    if (question && yell) {
        return "Calm down, I know what I'm doing!";
    } else if (question) {
        return "Sure.";
    } else if (yell) {
        return "Whoa, chill out!";
    } else if (space) {
        return "Fine. Be that way!";
    }
    return "Whatever.";
}
}  // namespace bob
