#pragma once

#include <array>
#include <string>
#include <vector>

using namespace std;

namespace kindergarten_garden {
enum class Plants {
    clover,
    grass,
    violets,
    radishes,
};

array<Plants, 4> plants(string diagram, string name);
}  // namespace kindergarten_garden
