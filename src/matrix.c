#include "matrix.h"

static inline void add_to_adj_list(cell_t *matrix, char cell, char adj_cell) {
    matrix[CHAR2INT(cell)].adj_matrix[CHAR2INT(adj_cell)] = true;
}

void matrix_init(cell_t *matrix) {
    // Init matrix
    for (int i = 0; i < MAT_SIZE; i++) {
        matrix[i].name = INT2CHAR(i);
        matrix[i].predecessor = -1;
        matrix[i].visited = false;

        for (int j = 0; j < MAT_SIZE; j++) {
            matrix[i].adj_matrix[j] = false;
        }
    }

    // Define connections
    add_to_adj_list(matrix, 'A', 'B');
    add_to_adj_list(matrix, 'A', 'F');

    add_to_adj_list(matrix, 'B', 'A');

    add_to_adj_list(matrix, 'C', 'D');
    add_to_adj_list(matrix, 'C', 'H');

    add_to_adj_list(matrix, 'D', 'C');
    add_to_adj_list(matrix, 'D', 'E');

    add_to_adj_list(matrix, 'E', 'D');
    add_to_adj_list(matrix, 'E', 'J');

    add_to_adj_list(matrix, 'F', 'A');
    add_to_adj_list(matrix, 'F', 'G');

    add_to_adj_list(matrix, 'G', 'F');
    add_to_adj_list(matrix, 'G', 'H');

    add_to_adj_list(matrix, 'H', 'C');
    add_to_adj_list(matrix, 'H', 'G');
    add_to_adj_list(matrix, 'H', 'I');

    add_to_adj_list(matrix, 'I', 'H');
    add_to_adj_list(matrix, 'I', 'N');

    add_to_adj_list(matrix, 'J', 'E');

    add_to_adj_list(matrix, 'K', 'P');

    add_to_adj_list(matrix, 'L', 'M');
    add_to_adj_list(matrix, 'L', 'Q');

    add_to_adj_list(matrix, 'M', 'L');
    add_to_adj_list(matrix, 'M', 'N');
    add_to_adj_list(matrix, 'M', 'R');

    add_to_adj_list(matrix, 'N', 'I');
    add_to_adj_list(matrix, 'N', 'M');
    add_to_adj_list(matrix, 'N', 'O');

    add_to_adj_list(matrix, 'O', 'N');

    add_to_adj_list(matrix, 'P', 'K');
    add_to_adj_list(matrix, 'P', 'U');

    add_to_adj_list(matrix, 'Q', 'L');
    add_to_adj_list(matrix, 'Q', 'V');

    add_to_adj_list(matrix, 'R', 'M');
    add_to_adj_list(matrix, 'R', 'S');

    add_to_adj_list(matrix, 'S', 'R');
    add_to_adj_list(matrix, 'S', 'T');

    add_to_adj_list(matrix, 'T', 'S');
    add_to_adj_list(matrix, 'T', 'Y');

    add_to_adj_list(matrix, 'U', 'P');
    add_to_adj_list(matrix, 'U', 'V');

    add_to_adj_list(matrix, 'V', 'Q');
    add_to_adj_list(matrix, 'V', 'U');
    add_to_adj_list(matrix, 'V', 'W');

    add_to_adj_list(matrix, 'W', 'V');
    add_to_adj_list(matrix, 'W', 'X');

    add_to_adj_list(matrix, 'X', 'W');
    add_to_adj_list(matrix, 'X', 'Y');

    add_to_adj_list(matrix, 'Y', 'T');
    add_to_adj_list(matrix, 'Y', 'X');
}

void matrix_print_path(const cell_t *matrix) {
    printf("Reconstructing path...\n");
    char path[MAT_SIZE];
    int path_idx = 0;
    char current = GOAL_CELL;

    if (matrix[CHAR2INT(current)].predecessor == -1) {
        printf("Goal cell %c is unreachable\n", GOAL_CELL);
        return;
    }

    while (current != START_CELL) {
        path[path_idx++] = current;
        
        int current_idx = CHAR2INT(current);
        
        int pred = matrix[current_idx].predecessor;
        if (pred == -1) {
            printf("No predecessor for %c, path reconstruction failed\n", current);
            return;
        }

        current = INT2CHAR(pred);
    }

    path[path_idx++] = START_CELL;

    printf("Path found: ");
    for (int i = path_idx - 1; i >= 0; i--) {
        printf("%c ", path[i]);
    }
    printf("\n");
}
