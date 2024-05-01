#include "hamming.h"

static char is_char_ptr(const char* ptr) {
    return (*ptr >= 'A' && *ptr <= 'Z');
}

int compute(const char* lhs, const char* rhs) {
    int ans = 0;
    for (; is_char_ptr(lhs) && is_char_ptr(rhs); lhs++, rhs++) {
        if (*rhs != *lhs) {
            ans++;
        }
    }
    if (is_char_ptr(lhs) || is_char_ptr(rhs)) {
        return -1;
    }
    return ans;
}