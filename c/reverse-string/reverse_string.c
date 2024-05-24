#include "reverse_string.h"

#include <stdlib.h>
#include <string.h>

char* reverse(const char* value) {
    size_t len = strlen(value);
    char* ans = calloc(len + 1, sizeof(char));
    for (size_t i = 0; i < len; i++) {
        ans[i] = value[len - i - 1];
    }
    return ans;
}