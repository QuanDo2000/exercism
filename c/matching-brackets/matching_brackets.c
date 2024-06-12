#include "matching_brackets.h"

bool is_paired(const char* input) {
    int len = 0;
    char stack[MAX_LEN];

    for (; (*input) != '\0'; input++) {
        char ch = (*input);
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[len++] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (len <= 0) return false;
            if (ch == ')' && stack[len - 1] == '(') {
                len--;
            } else if (ch == '}' && stack[len - 1] == '{') {
                len--;
            } else if (ch == ']' && stack[len - 1] == '[') {
                len--;
            } else {
                return false;
            }
        }
    }

    if (len > 0) return false;
    return true;
}