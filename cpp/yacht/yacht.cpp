#include "yacht.h"

#include <algorithm>
#include <numeric>

namespace yacht {
int score(vector<int> dices, string category) {
    sort(dices.begin(), dices.end());
    if (category == "ones") {
        return 1 * count(dices.begin(), dices.end(), 1);
    }
    if (category == "twos") {
        return 2 * count(dices.begin(), dices.end(), 2);
    }
    if (category == "threes") {
        return 3 * count(dices.begin(), dices.end(), 3);
    }
    if (category == "fours") {
        return 4 * count(dices.begin(), dices.end(), 4);
    }
    if (category == "fives") {
        return 5 * count(dices.begin(), dices.end(), 5);
    }
    if (category == "sixes") {
        return 6 * count(dices.begin(), dices.end(), 6);
    }
    if (category == "full house") {
        if ((dices[0] == dices[2] && dices[3] == dices[4] && dices[2] != dices[3]) ||
            (dices[0] == dices[1] && dices[2] == dices[4] && dices[1] != dices[2]))
            return reduce(dices.begin(), dices.end());
        return 0;
    }
    if (category == "four of a kind") {
        if (dices[0] == dices[3] || dices[1] == dices[4]) return dices[1] * 4;
        return 0;
    }
    if (category == "little straight") {
        if (reduce(dices.begin(), dices.end()) == 15) return 30;
        return 0;
    }
    if (category == "big straight") {
        if (reduce(dices.begin(), dices.end()) == 20) return 30;
        return 0;
    }
    if (category == "choice") {
        return reduce(dices.begin(), dices.end());
    }
    if (category == "yacht") {
        if (dices[0] == dices[4]) return 50;
        return 0;
    }
    return 0;
}
}  // namespace yacht
