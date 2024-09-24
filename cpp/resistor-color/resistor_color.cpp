#include "resistor_color.h"

namespace resistor_color {
vector<string> colors() {
    return {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
}

int color_code(string color) {
    vector<string> cs = colors();
    for (size_t i = 0; i < cs.size(); i++) {
        if (cs[i] == color) return i;
    }
    return -1;
}
}  // namespace resistor_color
