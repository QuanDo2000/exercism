#include "knapsack.h"

#include <algorithm>

namespace knapsack {
int maximum_value(int max_weight, const vector<Item> items) {
    if (items.size() == 0) return 0;

    Item item = items.front();
    vector<Item> newItems(items.begin() + 1, items.end());
    int null_value = maximum_value(max_weight, newItems);
    if (item.weight > max_weight) return null_value;
    int pick_value = maximum_value(max_weight - item.weight, newItems) + item.value;
    return max(pick_value, null_value);
}
}  // namespace knapsack
