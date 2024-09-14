#include "largest_series_product.h"

#include <cctype>
#include <stdexcept>

namespace largest_series_product {
int get_product(string series) {
    int ans = 1;
    for (char ch : series) {
        if (isdigit(ch)) ans *= ch - '0';
        if (isalpha(ch)) throw domain_error("invalid character");
    }
    return ans;
}

int largest_product(string input, int span) {
    if (span < 0 || span > (int)input.length()) throw domain_error("invalid span");
    int max = 0;
    for (size_t i = 0; i <= input.length() - span; i++) {
        int value = get_product(input.substr(i, span));
        if (value > max) max = value;
    }
    return max;
}
}  // namespace largest_series_product