#include "linked_list.h"

#include <stdlib.h>

struct list_node {
    struct list_node *prev, *next;
    ll_data_t data;
};

struct list {
    struct list_node *first, *last;
};

static struct list_node* new_node(ll_data_t data) {
    struct list_node* n = malloc(sizeof(struct list_node));
    n->prev = NULL;
    n->next = NULL;
    n->data = data;
    return n;
}

struct list* list_create(void) {
    struct list* l = malloc(sizeof(struct list));
    l->first = NULL;
    l->last = NULL;
    return l;
}

size_t list_count(const struct list* l) {
    size_t count = 0;
    struct list_node* node = l->first;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

void list_push(struct list* l, ll_data_t item_data) {
    struct list_node* n = new_node(item_data);

    if (l->first == NULL || l->last == NULL) {
        l->first = n;
        l->last = n;
    } else {
        l->last->next = n;
        n->prev = l->last;
        l->last = n;
    }
}

ll_data_t list_pop(struct list* l) {
    struct list_node* n = l->last;
    if (n == NULL) return 0;
    ll_data_t data = n->data;
    l->last = l->last->prev;
    if (l->last != NULL) {
        l->last->next = NULL;
    } else {
        l->first = NULL;
    }
    free(n);
    return data;
}

void list_unshift(struct list* l, ll_data_t item_data) {
    struct list_node* n = new_node(item_data);

    if (l->first == NULL || l->last == NULL) {
        l->first = n;
        l->last = n;
    } else {
        l->first->prev = n;
        n->next = l->first;
        l->first = n;
    }
}

ll_data_t list_shift(struct list* l) {
    struct list_node* n = l->first;
    if (n == NULL) return 0;
    ll_data_t data = n->data;
    l->first = l->first->next;
    if (l->first != NULL) {
        l->first->prev = NULL;
    } else {
        l->last = NULL;
    }
    free(n);
    return data;
}

void list_delete(struct list* l, ll_data_t data) {
    struct list_node* n = l->first;
    while (n != NULL && n->data != data) {
        n = n->next;
    }

    if (n == NULL) return;
    if (n->prev != NULL) n->prev->next = n->next;
    if (n->next != NULL) n->next->prev = n->prev;
    if (l->first == n) l->first = n->next;
    if (l->last == n) l->last = n->prev;
    free(n);
}

void list_destroy(struct list* l) {
    struct list_node* n = l->first;
    while (n != NULL) {
        struct list_node* nxt = n->next;
        free(n);
        n = nxt;
    }
    free(l);
}