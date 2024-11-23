#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack_node_s stack_node_t;
typedef struct stack_s stack_t;

struct stack_node_s {
    char cell;
    stack_node_t *next;
};

struct stack_s {
    stack_node_t *top;
    int nodes_allocated;
};

bool stack_empty(stack_t *s);
void stack_init(stack_t *s);
void stack_deinit(stack_t *s);
void stack_set(stack_t *s, char new_cell);
char stack_pop(stack_t *s);

#endif // STACK_H
