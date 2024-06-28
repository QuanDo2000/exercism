#include "binary_search_tree.h"

#include <stdlib.h>

static node_t* add_node(node_t* node, int data) {
    if (node == NULL) {
        node = malloc(sizeof(node_t));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (data <= node->data) {
        node->left = add_node(node->left, data);
    } else {
        node->right = add_node(node->right, data);
    }
    return node;
}

static void inorder(node_t* node, int* ans, int* idx) {
    if (node == NULL) {
        return;
    }
    inorder(node->left, ans, idx);
    ans[(*idx)++] = node->data;
    inorder(node->right, ans, idx);
}

node_t* build_tree(int* tree_data, size_t len) {
    node_t* root = add_node(NULL, tree_data[0]);
    for (size_t i = 1; i < len; i++) {
        add_node(root, tree_data[i]);
    }
    return root;
}

void free_tree(node_t* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int* sorted_data(node_t* tree) {
    int* ans = calloc(MAX_LEN, sizeof(int));
    int idx = 0;
    inorder(tree, ans, &idx);
    return ans;
}