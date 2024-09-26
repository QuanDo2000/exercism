#pragma once

#include <vector>

using namespace std;

namespace sublist {
enum class List_comparison {
    equal,
    sublist,
    superlist,
    unequal,
};

List_comparison sublist(vector<int> l1, vector<int> l2);
}  // namespace sublist
