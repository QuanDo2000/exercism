#include "darts.h"

#include <cmath>

namespace darts {
int score(double x, double y) {
    double radius = sqrt(x * x + y * y);
    if (radius > 10) return 0;
    if (radius > 5) return 1;
    if (radius > 1) return 5;
    return 10;
}
}  // namespace darts