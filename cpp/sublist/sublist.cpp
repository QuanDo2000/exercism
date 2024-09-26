#include "sublist.h"

#include <algorithm>

namespace sublist {
List_comparison sublist(vector<int> l1, vector<int> l2) {
    if (l1 == l2) return List_comparison::equal;

    if (l1.size() < l2.size()) {
        vector<int>::iterator pos = std::search(l2.begin(), l2.end(), l1.begin(), l1.end());
        if (pos != l2.end()) return List_comparison::sublist;
    } else {
        vector<int>::iterator pos = std::search(l1.begin(), l1.end(), l2.begin(), l2.end());
        if (pos != l1.end()) return List_comparison::superlist;
    }
    return List_comparison::unequal;
}
}  // namespace sublist
