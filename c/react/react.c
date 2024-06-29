#include "react.h"

#include <stdlib.h>

reactor_t* create_reactor(void) {
    reactor_t* r = malloc(sizeof(reactor_t) + MAX_CELLS * sizeof(cell_t*));
    r->num_cells = 0;
    return r;
}

void destroy_reactor(reactor_t* r) {
    for (size_t i = 0; i < r->num_cells; i++) {
        cell_t* c = r->cells[i];
        if (c == NULL) continue;
        free(c->cells);
        free(c->args);
        free(c->cbs);
        free(r->cells[i]);
    }
    free(r);
}

cell_t* create_input_cell(reactor_t* r, int initial_val) {
    cell_t* c = malloc(sizeof(cell_t));
    c->value = initial_val;
    c->cells = calloc(MAX_CELLS, sizeof(cell_t*));
    c->num_cells = 0;
    c->up1 = NULL;
    c->up2 = NULL;
    c->compute_1 = NULL;
    c->compute_2 = NULL;
    c->args = calloc(MAX_CALLBACKS, sizeof(void*));
    c->cbs = calloc(MAX_CALLBACKS, sizeof(callback));

    r->cells[r->num_cells++] = c;
    return c;
}

cell_t* create_compute1_cell(reactor_t* r, cell_t* c, compute1 comp1) {
    cell_t* cell = malloc(sizeof(cell_t));
    cell->value = comp1(c->value);
    cell->cells = calloc(MAX_CELLS, sizeof(cell_t*));
    cell->num_cells = 0;
    cell->up1 = c;
    cell->up2 = NULL;
    cell->compute_1 = comp1;
    cell->compute_2 = NULL;
    cell->args = calloc(MAX_CALLBACKS, sizeof(void*));
    cell->cbs = calloc(MAX_CALLBACKS, sizeof(callback));

    c->cells[c->num_cells++] = cell;
    r->cells[r->num_cells++] = cell;
    return cell;
}

cell_t* create_compute2_cell(reactor_t* r, cell_t* c1, cell_t* c2, compute2 comp2) {
    cell_t* c = malloc(sizeof(cell_t));
    c->value = comp2(c1->value, c2->value);
    c->cells = calloc(MAX_CELLS, sizeof(cell_t*));
    c->num_cells = 0;
    c->up1 = c1;
    c->up2 = c2;
    c->compute_1 = NULL;
    c->compute_2 = comp2;
    c->args = calloc(MAX_CALLBACKS, sizeof(void*));
    c->cbs = calloc(MAX_CALLBACKS, sizeof(callback));

    c1->cells[c1->num_cells++] = c;
    c2->cells[c2->num_cells++] = c;
    r->cells[r->num_cells++] = c;
    return c;
}

int get_cell_value(cell_t* c) {
    if (c->compute_1 != NULL && c->up1 != NULL) {
        c->value = (c->compute_1)(get_cell_value(c->up1));
    }
    if (c->compute_2 != NULL && c->up1 != NULL && c->up2 != NULL) {
        c->value = (c->compute_2)(get_cell_value(c->up1), get_cell_value(c->up2));
    }
    return c->value;
}

void set_cell_value(cell_t* c, int new_value) {
    if (c->value == new_value) return;
    c->value = new_value;
    for (size_t i = 0; i < c->num_cells; i++) {
        if (c->cells[i] == NULL) continue;
        cell_t* child = c->cells[i];
        if (child->compute_1 != NULL) {
            set_cell_value(child, (child->compute_1)(get_cell_value(child->up1)));
        }
        if (child->compute_2 != NULL) {
            set_cell_value(child, (child->compute_2)(get_cell_value(child->up1), get_cell_value(child->up2)));
        }
    }

    for (callback_id i = 0; i < MAX_CALLBACKS; i++) {
        if (c->cbs[i] == NULL && c->args[i] == NULL) continue;
        (c->cbs[i])(c->args[i], get_cell_value(c));
    }
}

callback_id add_callback(cell_t* c, void* arg, callback cb) {
    for (callback_id i = 0; i < MAX_CALLBACKS; i++) {
        if (c->cbs[i] == NULL && c->args[i] == NULL) {
            c->cbs[i] = cb;
            c->args[i] = arg;
            return i;
        }
    }
    return -1;
}

void remove_callback(cell_t* c, callback_id idx) {
    if (c->cbs[idx] == NULL && c->args[idx] == NULL) {
        return;
    }
    c->cbs[idx] = NULL;
    c->args[idx] = NULL;
}