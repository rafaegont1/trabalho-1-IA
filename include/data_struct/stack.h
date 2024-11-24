#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "data_struct/common.h"

typedef struct stack_s stack_t;

struct stack_s {
    node_t *top;
    int nodes_allocated;
};

bool stack_empty(stack_t *s);
void stack_init(stack_t *s);
void stack_deinit(stack_t *s);
void stack_set(stack_t *s, int new_cell);
int stack_pop(stack_t *s);

#endif // STACK_H
