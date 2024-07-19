#include "grains.h"

namespace grains {
unsigned long long square(int i) {
    return (unsigned long long)1 << (i - 1);
}

unsigned long long total() {
    return -1;
}
}  // namespace grains
