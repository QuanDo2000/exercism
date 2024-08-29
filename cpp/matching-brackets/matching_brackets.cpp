#include "matching_brackets.h"

namespace matching_brackets {
bool check(string brackets) {
    stack<char> s;
    for (char ch : brackets) {
        switch (ch) {
            case '(':
                s.push(')');
                break;
            case '[':
                s.push(']');
                break;
            case '{':
                s.push('}');
                break;
            case ')':
            case ']':
            case '}':
                if (!s.empty() && s.top() == ch)
                    s.pop();
                else
                    return false;
            default:
                break;
        }
    }
    return s.empty();
}
}  // namespace matching_brackets
