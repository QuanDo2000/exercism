#include "knapsack.h"

unsigned int maximum_value(unsigned int max_weight, item_t* items, size_t item_count) {
    if (item_count == 0 || max_weight == 0) return 0;

    item_t item = items[item_count - 1];
    unsigned int picked = 0, not_picked = 0;
    if (item.weight <= max_weight) {
        picked = maximum_value(max_weight - item.weight, items, item_count - 1) + item.value;
    }
    not_picked = maximum_value(max_weight, items, item_count - 1);

    if (picked > not_picked) return picked;
    return not_picked;
}