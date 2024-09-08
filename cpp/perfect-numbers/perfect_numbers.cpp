#include "perfect_numbers.h"

#include <stdexcept>

namespace perfect_numbers {
classification classify(int num) {
    if (num <= 0) throw std::domain_error("invalid input");

    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (num == sum)
        return classification::perfect;
    else if (num < sum)
        return classification::abundant;
    else
        return classification::deficient;
}
}  // namespace perfect_numbers
