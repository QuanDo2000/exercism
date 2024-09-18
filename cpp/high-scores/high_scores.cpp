#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    std::vector<int> result(scores.size() < 3 ? scores.size() : 3);
    std::partial_sort_copy(scores.begin(), scores.end(), result.begin(), result.end(), std::greater<int>());
    return result;
}

}  // namespace arcade
