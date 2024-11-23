#include "stack.h"

#include <stdlib.h>
#include <assert.h>
// #include "malloc_dbg.h"

bool stack_empty(stack_t *s) {
    return s->top == NULL;
}

void stack_init(stack_t *s) {
    s->top = NULL;
    s->nodes_allocated = 0;
}

void stack_deinit(stack_t *s) {
    stack_node_t *rm;

    while (!stack_empty(s)) {
        rm = s->top;
        s->top = rm->next;
        free(rm);
    }
}

void stack_set(stack_t *s, char new_cell) {
    stack_node_t *new_node = (stack_node_t *)malloc(sizeof(stack_node_t));
    stack_node_t *prev_top = s->top;

    new_node->cell = new_cell;

    s->top = new_node;
    new_node->next = prev_top;

    s->nodes_allocated++;
}

char stack_pop(stack_t *s) {
    char top_cell;
    stack_node_t *rm;

    assert(!stack_empty(s));

    rm = s->top;
    top_cell = rm->cell;
    s->top = rm->next;

    free(rm);

    return top_cell;
}
