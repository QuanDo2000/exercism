#include "list_ops.h"

list_t* new_list(size_t length, list_element_t elements[]) {
    list_t* l = calloc(1, sizeof(list_t) + (sizeof(list_element_t) * length));
    l->length = length;
    if (elements) {
        for (size_t i = 0; i < length; i++) {
            l->elements[i] = elements[i];
        }
    }
    return l;
}

list_t* append_list(list_t* list1, list_t* list2) {
    list_t* l = new_list(list1->length + list2->length, NULL);
    for (size_t i = 0; i < list1->length; i++) {
        l->elements[i] = list1->elements[i];
    }
    for (size_t i = 0; i < list2->length; i++) {
        l->elements[list1->length + i] = list2->elements[i];
    }
    return l;
}

list_t* filter_list(list_t* list, bool (*filter)(list_element_t)) {
    list_t* l = new_list(list->length, NULL);
    l->length = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) l->elements[l->length++] = list->elements[i];
    }
    l = realloc(l, sizeof(list_t) + sizeof(list_element_t) * l->length);
    return l;
}

size_t length_list(list_t* list) {
    return list->length;
}

list_t* map_list(list_t* list, list_element_t (*map)(list_element_t)) {
    list_t* l = new_list(list->length, NULL);
    for (size_t i = 0; i < list->length; i++) {
        l->elements[i] = map(list->elements[i]);
    }
    return l;
}

list_element_t foldl_list(list_t* list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)) {
    for (size_t i = 0; i < list->length; i++) {
        initial = foldl(list->elements[i], initial);
    }
    return initial;
}

list_element_t foldr_list(list_t* list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t)) {
    for (size_t i = 0; i < list->length; i++) {
        initial = foldr(list->elements[list->length - i - 1], initial);
    }
    return initial;
}

list_t* reverse_list(list_t* list) {
    list_t* l = new_list(list->length, NULL);
    for (size_t i = 0; i < list->length; i++) {
        l->elements[i] = list->elements[list->length - i - 1];
    }
    return l;
}

void delete_list(list_t* list) {
    free(list);
}