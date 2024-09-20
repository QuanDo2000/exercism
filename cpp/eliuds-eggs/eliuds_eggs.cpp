#include "eliuds_eggs.h"

namespace chicken_coop {
int positions_to_quantity(int positions) {
    int count = 0;
    while (positions > 0) {
        count += positions % 2;
        positions /= 2;
    }
    return count;
}
}  // namespace chicken_coop
