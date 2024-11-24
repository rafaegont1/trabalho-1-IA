#ifndef COMMON_H
#define COMMON_H

typedef struct node_s node_t;

struct node_s {
    char data;
    node_t *next;
};

#endif // COMMON_H
