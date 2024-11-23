#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_node_s queue_node_t;
typedef struct queue_s queue_t;

struct queue_node_s {
    char cell;
    queue_node_t *next;
};

struct queue_s {
    queue_node_t *first;
    int nodes_allocated;
};

bool queue_empty(queue_t *q);
void queue_init(queue_t *q);
void queue_deinit(queue_t *q);
void queue_set(queue_t *q, char new_cell);
char queue_pop(queue_t *q);

#endif // QUEUE_H
