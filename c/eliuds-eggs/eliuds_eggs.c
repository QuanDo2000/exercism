#include "eliuds_eggs.h"

int egg_count(int decimal) {
    int ans = 0;
    for (; decimal > 0; decimal >>= 1) {
        ans += decimal & 1;
    }
    return ans;
}