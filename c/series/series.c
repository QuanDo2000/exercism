#include "series.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

slices_t slices(char* input, unsigned int sublen) {
    size_t input_len = strlen(input);
    if (sublen <= 0 || sublen > input_len) return (slices_t){0, NULL};

    slices_t ans;
    ans.substring_count = input_len - sublen + 1;
    ans.substring = calloc(ans.substring_count, sizeof(char*));
    for (unsigned int i = 0; i < ans.substring_count; i++) {
        ans.substring[i] = calloc(sublen + 1, sizeof(char));
    }

    for (unsigned int i = 0; i < ans.substring_count; i++) {
        memcpy(ans.substring[i], input + i, sizeof(char) * sublen);
    }
    printf("%d", ans.substring_count);
    return ans;
}