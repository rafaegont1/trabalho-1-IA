#include "data_struct/stack.h"

#include <stdlib.h>
#include <assert.h>

bool stack_empty(stack_t *s) {
    return s->top == NULL;
}

void stack_init(stack_t *s) {
    s->top = NULL;
    s->nodes_allocated = 0;
}

void stack_deinit(stack_t *s) {
    node_t *rm;

    while (!stack_empty(s)) {
        rm = s->top;
        s->top = rm->next;
        free(rm);
    }
}

void stack_set(stack_t *s, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = data;
    new_node->next = s->top;

    s->top = new_node;

    s->nodes_allocated++;
}

int stack_pop(stack_t *s) {
    assert(!stack_empty(s));

    int popped_data;
    node_t *rm = s->top;

    popped_data = rm->data;
    s->top = rm->next;

    free(rm);

    return popped_data;
}
