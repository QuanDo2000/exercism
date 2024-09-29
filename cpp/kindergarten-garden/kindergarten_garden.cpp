#include "kindergarten_garden.h"

#include <stdexcept>

namespace kindergarten_garden {
Plants get_plant(char code) {
    switch (code) {
        case 'V':
            return Plants::violets;
        case 'R':
            return Plants::radishes;
        case 'C':
            return Plants::clover;
        case 'G':
            return Plants::grass;
        default:
            return Plants::grass;
    }
}

array<Plants, 4> plants(string diagram, string name) {
    size_t idx = (name[0] - 'A') * 2;
    size_t enter_idx = diagram.find('\n');
    if (idx > diagram.length() / 2) throw invalid_argument("diagram too short");
    vector<size_t> idxs = {idx, idx + 1, enter_idx + idx + 1, enter_idx + idx + 2};

    array<Plants, 4> ans;
    for (size_t i = 0; i < idxs.size(); i++) {
        ans[i] = get_plant(diagram[idxs[i]]);
    }
    return ans;
}
}  // namespace kindergarten_garden
