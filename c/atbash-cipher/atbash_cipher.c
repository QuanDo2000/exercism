#include "atbash_cipher.h"

#include <stdlib.h>
#include <string.h>

char* atbash_encode(const char* input) {
    const size_t len = strlen(input);
    char* ans = calloc(MAX_LEN, sizeof(char));

    int idx = 0;
    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            ans[idx++] = 'z' - ch + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ans[idx++] = 'Z' - ch + 'a';
        } else if (ch >= '0' && ch <= '9') {
            ans[idx++] = ch;
        }

        if (idx % 6 == 5) {
            ans[idx++] = ' ';
        }
    }

    if (ans[idx - 1] == ' ') {
        ans[--idx] = '\0';
    }

    return ans;
}

char* atbash_decode(const char* input) {
    const size_t len = strlen(input);
    char* ans = calloc(MAX_LEN, sizeof(char));

    int idx = 0;
    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            ans[idx++] = 'z' - ch + 'a';
        } else if (ch >= '0' && ch <= '9') {
            ans[idx++] = ch;
        }
    }
    return ans;
}