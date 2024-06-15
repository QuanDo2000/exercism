#include "secret_handshake.h"

#include <stdlib.h>

static char* actions[] = {"wink", "double blink", "close your eyes", "jump"};

const char** commands(size_t number) {
    const char** ans = calloc(MAX_ACTIONS, sizeof(char*));
    int idx = 0, idx_incr = 1, len = 0, end = MAX_ACTIONS;
    if (number & (1 << MAX_ACTIONS)) {
        idx = MAX_ACTIONS - 1;
        idx_incr = -1;
        end = -1;
    }

    for (; idx != end; idx += idx_incr) {
        if (number & (1 << idx)) {
            ans[len++] = actions[idx];
        }
    }
    return ans;
}