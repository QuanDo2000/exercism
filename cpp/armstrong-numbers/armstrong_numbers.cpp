#include "armstrong_numbers.h"

namespace armstrong_numbers {
bool is_armstrong_number(int num) {
    int len = floor(log10(num)) + 1;

    int ans = 0;
    for (int curr = num; curr > 0; curr /= 10) {
        ans += pow(curr % 10, len);
    }
    return ans == num;
}
}  // namespace armstrong_numbers
