#include "binary_search.h"

#include <stdexcept>

namespace binary_search {
size_t find(vector<int> data, int num) {
    int lo = 0, hi = data.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (data[mid] == num) {
            return mid;
        } else if (data[mid] > num) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    throw domain_error("value not found");
}
}  // namespace binary_search
