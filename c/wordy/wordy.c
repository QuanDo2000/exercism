#include "wordy.h"

#include <stdlib.h>
#include <string.h>

const char* DELIM = " ?";
const char* ERRORS[NUM_ERRORS] = {"cubed", "Who"};

bool answer(const char* question, int* result) {
    const size_t len = strlen(question);
    char* q = calloc(len + 1, sizeof(char));
    strcpy(q, question);

    (*result) = 0;

    char* token = strtok(q, DELIM);
    int op = 0;
    while (token != NULL) {
        int t = strtol(token, NULL, 10);
        if (t == 0) {
            for (int i = 0; i < NUM_ERRORS; i++) {
                if (strcmp(token, ERRORS[i]) == 0) {
                    free(q);
                    return 0;
                }
            }
            if (strcmp(token, "plus") == 0) {
                if (op == 1 || (*result == 0)) {
                    free(q);
                    return 0;
                }
                op = 1;
            }
            if (strcmp(token, "minus") == 0) {
                if (op == 2 || (*result == 0)) {
                    free(q);
                    return 0;
                }
                op = 2;
            }
            if (strcmp(token, "multiplied") == 0) {
                if (op == 3 || (*result == 0)) {
                    free(q);
                    return 0;
                }
                op = 3;
            }
            if (strcmp(token, "divided") == 0) {
                if (op == 4 || (*result == 0)) {
                    free(q);
                    return 0;
                }
                op = 4;
            }
        } else {
            switch (op) {
                case 0:
                    (*result) = t;
                    break;
                case 1:
                    (*result) += t;
                    break;
                case 2:
                    (*result) -= t;
                    break;
                case 3:
                    (*result) *= t;
                    break;
                case 4:
                    (*result) /= t;
                    break;
                default:
                    break;
            }
            op = 0;
        }
        token = strtok(NULL, DELIM);
    }
    free(q);

    if ((*result) == 0) return 0;
    return op == 0 ? 1 : 0;
}