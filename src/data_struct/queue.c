#include "data_struct/queue.h"

#include <stdlib.h>
#include <assert.h>

bool queue_empty(queue_t *q) {
    return q->first == NULL;
}

void queue_init(queue_t *q) {
    q->first = NULL;
    q->nodes_allocated = 0;
}

void queue_deinit(queue_t *q) {
    node_t *rm;

    while (!queue_empty(q)) {
        rm = q->first;
        q->first = rm->next;
        free(rm);
    }
}

void queue_set(queue_t *q, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = data;
    new_node->next = NULL;

    if (queue_empty(q)) {
        q->first = new_node;
    } else {
        node_t *iter = q->first;

        while (iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = new_node;
    }

    q->nodes_allocated++;
}

int queue_pop(queue_t *q) {
    assert(!queue_empty(q));

    int popped_data;
    node_t *rm = q->first;

    popped_data = rm->data;
    q->first = rm->next;

    free(rm);

    return popped_data;
}
