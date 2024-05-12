#include "binary_search.h"

const int* binary_search(int value, const int* arr, size_t length) {
    if (!arr) return NULL;
    int lo = 0, hi = length;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == value) {
            return &arr[mid];
        } else if (arr[mid] > value) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return NULL;
}