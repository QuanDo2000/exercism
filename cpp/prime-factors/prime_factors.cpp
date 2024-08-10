#include "prime_factors.h"

namespace prime_factors {
vector<int> of(int num) {
    vector<int> ans;
    int factor = 2;
    while (num > 1) {
        if (num % factor == 0) {
            num /= factor;
            ans.emplace_back(factor);
        } else {
            factor++;
        }
    }
    return ans;
}
}  // namespace prime_factors
