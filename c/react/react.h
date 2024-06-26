#ifndef REACT_H
#define REACT_H

#include <stddef.h>

#define MAX_CELLS 100
#define MAX_CALLBACKS 100

typedef struct cell cell_t;
typedef struct reactor reactor_t;

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

reactor_t* create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(reactor_t*);

cell_t* create_input_cell(reactor_t*, int initial_value);
cell_t* create_compute1_cell(reactor_t*, cell_t*, compute1);
cell_t* create_compute2_cell(reactor_t*, cell_t*, cell_t*, compute2);

int get_cell_value(cell_t*);
void set_cell_value(cell_t*, int new_value);

typedef void (*callback)(void*, int);
typedef int callback_id;

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(cell_t*, void*, callback);
void remove_callback(cell_t*, callback_id);

struct cell {
    int value;
    cell_t** cells;
    size_t num_cells;
    cell_t* up1;
    cell_t* up2;
    compute1 compute_1;
    compute2 compute_2;
    void** args;
    callback* cbs;
};
struct reactor {
    size_t num_cells;
    cell_t* cells[];
};

#endif
