#include "gigasecond.h"

namespace gigasecond {
ptime advance(ptime time) {
    return time + seconds(1000000000);
}
}  // namespace gigasecond
