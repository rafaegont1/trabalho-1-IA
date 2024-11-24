#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "data_struct/common.h"

typedef struct queue_s queue_t;

struct queue_s {
    node_t *first;
    int nodes_allocated;
};

bool queue_empty(queue_t *q);
void queue_init(queue_t *q);
void queue_deinit(queue_t *q);
void queue_set(queue_t *q, int data);
int queue_pop(queue_t *q);

#endif // QUEUE_H
