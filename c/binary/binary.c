#include "binary.h"

#include <string.h>

int convert(const char* input) {
    size_t binary_length = strlen(input);

    int ans = 0;
    for (unsigned int i = 0; i < binary_length; i++) {
        ans *= 2;
        switch (input[i]) {
            case '1':
                ans++;
                break;
            case '0':
                continue;
            default:
                return INVALID;
        }
    }
    return ans;
}