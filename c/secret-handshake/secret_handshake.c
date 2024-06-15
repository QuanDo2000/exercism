#include "secret_handshake.h"

#include <stdlib.h>

static char* actions[] = {"wink", "double blink", "close your eyes", "jump"};

static void reverse(const char** ans, int len) {
    for (int i = 0; i < len / 2; i++) {
        const char* temp = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = temp;
    }
}

const char** commands(size_t number) {
    const char** ans = calloc(MAX_ACTIONS, sizeof(char*));
    int idx = 0, len = 0;
    while (number > 0 && idx < MAX_ACTIONS) {
        int include = number % 2;

        if (include) ans[len++] = actions[idx];

        number >>= 1;
        idx++;
    }
    if (number > 0) reverse(ans, len);
    return ans;
}