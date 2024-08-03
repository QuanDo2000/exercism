#include "secret_handshake.h"

namespace secret_handshake {
vector<string> actions = {
    "wink",
    "double blink",
    "close your eyes",
    "jump",
};
const unsigned int REVERSE = (1 << 4);

vector<string> commands(int c) {
    vector<string> ans;
    int action = 0, incr = 1, end = actions.size();
    if (c & REVERSE) {
        action = actions.size() - 1;
        incr = -1;
        end = -1;
    }

    for (; action != end; action += incr) {
        if (c & (1 << action)) {
            ans.emplace_back(actions[action]);
        }
    }
    return ans;
}
}  // namespace secret_handshake
