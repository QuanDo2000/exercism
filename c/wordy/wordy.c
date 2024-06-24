#include "wordy.h"

#include <stdio.h>
#include <string.h>

bool answer(const char* question, int* result) {
    if (!question || !result) return 0;

    int count = 0;
    size_t len = strlen(question);

    if (sscanf(question, "What is %d %n", result, &count) == 0) {
        return 0;
    }
    question += count;
    len -= count;

    int t = 0;
    while (len > 1) {
        if (sscanf(question, " plus %d %n", &t, &count)) {
            (*result) += t;
        } else if (sscanf(question, "minus %d %n", &t, &count)) {
            (*result) -= t;
        } else if (sscanf(question, "multiplied by %d %n", &t, &count)) {
            (*result) *= t;
        } else if (sscanf(question, "divided by %d %n", &t, &count)) {
            (*result) /= t;
        } else {
            return 0;
        }

        question += count;
        len -= count;
    }

    if (strcmp(question, "?")) return 0;
    return 1;
}