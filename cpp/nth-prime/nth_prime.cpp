#include "nth_prime.h"

#include <stdexcept>

namespace nth_prime {
bool check_prime(int n) {
    for (int i = 2; i <= (n / 2) + 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nth(int i) {
    if (i <= 0) throw std::domain_error("invalid index");

    int count = 1, p = 2;
    while (count < i) {
        if (check_prime(p)) count++;
        if (count == i) return p;
        p++;
    }
    return p;
}
}  // namespace nth_prime
