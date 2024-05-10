#include "pangram.h"

bool is_pangram(const char* sentence) {
    if (!sentence) {
        return false;
    }

    long ans = 0;
    char ch;
    while ((ch = *sentence) != '\0') {
        if (ch >= 'a' && ch <= 'z') {
            ans |= 1 << (ch - 'a');
        } else if (ch >= 'A' && ch <= 'Z') {
            ans |= 1 << (ch - 'A');
        }
        sentence++;
    }
    return ans == (1 << 26) - 1;
}