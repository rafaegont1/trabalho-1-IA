#include "queue.h"

#include <stdlib.h>
#include <assert.h>
// #include "malloc_dbg.h"

bool queue_empty(queue_t *q) {
    return q->first == NULL;
}

void queue_init(queue_t *q) {
    q->first = NULL;
    q->nodes_allocated = 0;
}

void queue_deinit(queue_t *q) {
    queue_node_t *rm;

    while (!queue_empty(q)) {
        rm = q->first;
        q->first = rm->next;
        free(rm);
    }
}

void queue_set(queue_t *q, char new_cell) {
    queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));

    new_node->cell = new_cell;
    new_node->next = NULL;

    if (queue_empty(q)) {
        q->first = new_node;
    } else {
        queue_node_t *iter = q->first;

        while (iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = new_node;
    }

    q->nodes_allocated++;
}

char queue_pop(queue_t *q) {
    char first_cell;
    queue_node_t *rm;

    assert(!queue_empty(q));

    rm = q->first;
    first_cell = rm->cell;
    q->first = rm->next;

    free(rm);

    return first_cell;
}
