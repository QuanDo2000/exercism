#include "all_your_base.h"

#include <cmath>
#include <stdexcept>

namespace all_your_base {
vector<unsigned int> convert(unsigned int input_base, vector<unsigned int> digits, unsigned int output_base) {
    if (input_base <= 1 || output_base <= 1) throw std::invalid_argument("invalid argument");

    int val = 0;
    int p = digits.size() - 1;
    for (unsigned int d : digits) {
        if (d >= input_base) throw std::invalid_argument("invalid digits");
        val += d * pow(input_base, p--);
    }

    vector<unsigned int> ans;
    while (val > 0) {
        int digit = val % output_base;
        ans.emplace(ans.begin(), digit);
        val /= output_base;
    }
    return ans;
}
}  // namespace all_your_base
