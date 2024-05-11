#include "armstrong_numbers.h"

bool is_armstrong_number(int num) {
    int num_digits = 0;
    int temp = num;
    while (temp > 0) {
        temp /= 10;
        ++num_digits;
    }

    int ans = 0;
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        int pow = digit;
        for (int i = 1; i < num_digits; i++) {
            pow *= digit;
        }
        ans += pow;
        temp /= 10;
    }

    return ans == num;
}