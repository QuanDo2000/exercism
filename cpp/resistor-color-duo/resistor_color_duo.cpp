#include "resistor_color_duo.h"

namespace resistor_color_duo {
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

int value(vector<string> colors) {
    int ans = 0;
    for (size_t i = 0; i < 2; i++) {
        string color = colors[i];
        ans *= 10;
        ans += color_code(color);
    }
    return ans;
}
}  // namespace resistor_color_duo
