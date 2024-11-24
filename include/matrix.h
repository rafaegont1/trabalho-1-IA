#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdbool.h>
#include "util.h"

typedef struct {
    char name;
    int predecessor;
    bool visited;
    bool adj_matrix[MAT_SIZE];
} cell_t;

void matrix_init(cell_t *matrix);
void matrix_print_path(const cell_t *matrix);

#endif // CELL_H
