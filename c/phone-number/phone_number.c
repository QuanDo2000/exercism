#include "phone_number.h"

#include <stdlib.h>
#include <string.h>

#define MAX_LEN 11
#define FINAL_LEN 10

static void invalidate(char* res) {
    memset(res, '0', FINAL_LEN);
    res[FINAL_LEN] = '\0';
}

char* phone_number_clean(const char* input) {
    size_t input_len = strlen(input);
    char* res = calloc(MAX_LEN + 1, sizeof(char));

    size_t len = 0;
    for (size_t i = 0; i < input_len; i++) {
        char ch = input[i];
        if (ch >= '0' && ch <= '9') {
            if (len == 0 && (ch == '0' || ch == '1')) continue;
            res[len++] = ch;
        }
    }
    if (len < 10 || len > 11 ||
        (len == 11 && res[0] != '1')) {
        invalidate(res);
    }

    if (res[0] == '0' || res[0] == '1' || res[3] == '0' || res[3] == '1') {
        invalidate(res);
    }
    return res;
}