#include "sublist.h"

comparison_result_t check_lists(int* list_to_compare, int* base_list, size_t list_to_compare_element_count, size_t base_list_element_count) {
    char sublist = list_to_compare_element_count <= base_list_element_count;
    int* small_list = sublist ? list_to_compare : base_list;
    int* large_list = sublist ? base_list : list_to_compare;

    size_t min = sublist ? list_to_compare_element_count : base_list_element_count;
    size_t max = sublist ? base_list_element_count : list_to_compare_element_count;

    for (size_t i = 0; i <= max - min; i++) {
        size_t j;
        for (j = 0; j < min; j++) {
            if (small_list[j] != large_list[i + j]) break;
        }
        if (j == min) {
            if (min == max) return EQUAL;
            if (sublist) return SUBLIST;
            return SUPERLIST;
        }
    }
    return UNEQUAL;
}