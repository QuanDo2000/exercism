#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

using namespace std;

namespace knapsack {
struct Item {
    int weight;
    int value;
};

int maximum_value(int max_weight, const vector<Item> items);
}  // namespace knapsack

#endif  // KNAPSACK_H
