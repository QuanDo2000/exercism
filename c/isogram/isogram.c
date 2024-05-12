#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (!phrase) {
        return false;
    }

    long long flag = 0;
    int i = 0;
    char ch;
    while ((ch = phrase[i++]) != '\0') {
        int shift = 0;
        if (ch >= 'a' && ch <= 'z') {
            shift = ch - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            shift = ch - 'A';
        } else {
            continue;
        }
        if ((flag & (1 << shift)) != 0) {
            return false;
        }
        flag |= (1 << shift);
    }

    return true;
}