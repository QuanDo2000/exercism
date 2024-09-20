#include "diamond.h"

#include <iostream>

namespace diamond {
vector<string> rows(char ch) {
    int len = (ch - 'A') * 2 + 1;
    int mid = len / 2;

    vector<string> ans;
    for (int i = 0; i < len; i++) {
        string line(len, ' ');
        int idx = i < mid ? i : (len - 1) - i;
        char ch = 'A' + idx;
        int right = mid + idx;
        int left = mid - idx;
        line[right] = ch;
        line[left] = ch;
        ans.emplace_back(line);
    }
    return ans;
}
}  // namespace diamond
