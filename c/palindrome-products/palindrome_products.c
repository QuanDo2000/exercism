#include "palindrome_products.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int is_palindrome(int num) {
    if (num < 10) return 1;

    char* str = calloc(MAX_LEN, sizeof(char));
    sprintf(str, "%d", num);

    const size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            free(str);
            return 0;
        }
    }
    free(str);
    return 1;
}

static void free_factor(factor_t* f) {
    if (f == NULL) return;

    factor_t* curr = f;
    while (curr != NULL) {
        factor_t* nxt = curr->next;
        free(curr);
        curr = nxt;
    }
    f = NULL;
}

product_t* get_palindrome_product(int from, int to) {
    product_t* ans = malloc(sizeof(product_t));
    ans->smallest = 0;
    ans->largest = 0;
    ans->factors_sm = NULL;
    ans->factors_lg = NULL;

    if (from > to) {
        sprintf(ans->error, "invalid input: min is %d and max is %d", from, to);
        return ans;
    }

    for (int i = from; i <= to; i++) {
        for (int j = i; j <= to; j++) {
            int p = i * j;
            if (!(p > ans->smallest && p < ans->largest) && is_palindrome(p)) {
                factor_t* product = malloc(sizeof(factor_t));
                product->factor_a = i;
                product->factor_b = j;
                product->next = NULL;

                if (p > ans->largest || ans->largest == 0) {
                    if (ans->factors_lg != ans->factors_sm) free_factor(ans->factors_lg);
                    ans->largest = p;
                    ans->factors_lg = product;
                } else if (p == ans->largest) {
                    factor_t* last_node = ans->factors_lg;
                    while (last_node->next != NULL) last_node = last_node->next;
                    last_node->next = product;
                }

                if (p < ans->smallest || ans->smallest == 0) {
                    if (ans->factors_lg != ans->factors_sm) free_factor(ans->factors_sm);
                    ans->smallest = p;
                    ans->factors_sm = product;
                } else if (p == ans->smallest) {
                    factor_t* last_node = ans->factors_sm;
                    while (last_node->next != NULL) last_node = last_node->next;
                    last_node->next = product;
                }
            }
        }
    }

    if (ans->factors_lg == NULL && ans->factors_sm == NULL) {
        sprintf(ans->error, "no palindrome with factors in the range %d to %d", from, to);
    }

    return ans;
}

void free_product(product_t* p) {
    free_factor(p->factors_lg);
    free_factor(p->factors_sm);
    free(p);
}