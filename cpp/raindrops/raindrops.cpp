#include "raindrops.h"

namespace raindrops {
std::string convert(int n) {
    std::string res = "";
    if (n % 3 == 0) res += "Pling";
    if (n % 5 == 0) res += "Plang";
    if (n % 7 == 0) res += "Plong";
    if (res == "") res = std::to_string(n);
    return res;
}
}  // namespace raindrops
