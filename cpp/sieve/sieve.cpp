#include "sieve.h"

namespace sieve {
std::vector<int> primes(int limit) {
    std::vector<int> ans;
    std::vector<bool> ps(limit + 1, false);
    for (int num = 2; num <= limit; num++) {
        if (ps[num]) continue;

        ans.emplace_back(num);
        for (int i = num + num; i <= limit; i += num) {
            ps[i] = true;
        }
    }
    return ans;
}
}  // namespace sieve
