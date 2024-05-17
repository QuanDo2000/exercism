#include "luhn.h"

bool luhn(const char* num) {
    if (!num) return false;

    int sum0 = 0, sum1 = 0, len = 0;
    for (; *num != '\0'; num++) {
        char ch = *num;
        if (ch >= '0' && ch <= '9') {
            int n = ch - '0';
            int t = n * 2;
            if (t > 9) t -= 9;
            if (len % 2 == 0) {
                sum0 += t;
                sum1 += n;
            } else {
                sum0 += n;
                sum1 += t;
            }
            len++;
        } else if (ch == ' ') {
            continue;
        } else {
            return false;
        }
    }

    if (len <= 1) return false;
    if (len % 2 == 0)
        return sum0 % 10 == 0;
    else
        return sum1 % 10 == 0;
}