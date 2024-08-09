#include "sum_of_multiples.h"

#include <set>

namespace sum_of_multiples {
int to(vector<int> values, int limit) {
    int ans = 0;
    for (int i = 0; i < limit; i++) {
        for (int value : values) {
            if (i % value == 0) {
                ans += i;
                break;
            }
        }
    }
    return ans;
}
}  // namespace sum_of_multiples
