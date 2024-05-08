#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t max = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > output[0]) {
            output[2] = output[1];
            output[1] = output[0];
            output[0] = scores[i];
        } else if (scores[i] <= output[0] && scores[i] > output[1]) {
            output[2] = output[1];
            output[1] = scores[i];
        } else if (scores[i] <= output[1] && scores[i] > output[2]) {
            output[2] = scores[i];
        }
    }

    if (scores_len < 3) {
        return scores_len;
    }
    return 3;
}