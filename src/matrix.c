#include "matrix.h"

void mat_set_path(bool *mat, char src, char dst) {
    mat[ADJ_MAT_IDX(src, dst)] = true;
}

bool mat_get_path(bool *mat, char src, char dst) {
    return mat[ADJ_MAT_IDX(src, dst)];
}

void mat_init(matrix_t *m) {
    // Init visited matrix
    for (int i = 0; i < MAT_SIZE; i++) {
        m->vis[i] = false;
    }

    // Init adjacence matrix
    for (int i = 0; i < MAT_SIZE * MAT_SIZE; i++) {
        m->adj[i] = false;
    }
    
    // Define connections
    mat_set_path(m->adj, 'A', 'B');
    mat_set_path(m->adj, 'A', 'F');

    mat_set_path(m->adj, 'B', 'A');

    mat_set_path(m->adj, 'C', 'D');
    mat_set_path(m->adj, 'C', 'H');

    mat_set_path(m->adj, 'D', 'C');
    mat_set_path(m->adj, 'D', 'E');

    mat_set_path(m->adj, 'E', 'D');
    mat_set_path(m->adj, 'E', 'J');

    mat_set_path(m->adj, 'F', 'A');
    mat_set_path(m->adj, 'F', 'G');

    mat_set_path(m->adj, 'G', 'F');
    mat_set_path(m->adj, 'G', 'H');

    mat_set_path(m->adj, 'H', 'C');
    mat_set_path(m->adj, 'H', 'G');
    mat_set_path(m->adj, 'H', 'I');

    mat_set_path(m->adj, 'I', 'H');
    mat_set_path(m->adj, 'I', 'N');

    mat_set_path(m->adj, 'J', 'E');

    mat_set_path(m->adj, 'K', 'P');

    mat_set_path(m->adj, 'L', 'M');
    mat_set_path(m->adj, 'L', 'Q');

    mat_set_path(m->adj, 'M', 'L');
    mat_set_path(m->adj, 'M', 'N');
    mat_set_path(m->adj, 'M', 'R');

    mat_set_path(m->adj, 'N', 'I');
    mat_set_path(m->adj, 'N', 'M');
    mat_set_path(m->adj, 'N', 'O');

    mat_set_path(m->adj, 'O', 'N');

    mat_set_path(m->adj, 'P', 'K');
    mat_set_path(m->adj, 'P', 'U');

    mat_set_path(m->adj, 'Q', 'L');
    mat_set_path(m->adj, 'Q', 'V');

    mat_set_path(m->adj, 'R', 'M');
    mat_set_path(m->adj, 'R', 'S');

    mat_set_path(m->adj, 'S', 'R');
    mat_set_path(m->adj, 'S', 'T');

    mat_set_path(m->adj, 'T', 'S');
    mat_set_path(m->adj, 'T', 'Y');

    mat_set_path(m->adj, 'U', 'P');
    mat_set_path(m->adj, 'U', 'V');

    mat_set_path(m->adj, 'V', 'Q');
    mat_set_path(m->adj, 'V', 'U');
    mat_set_path(m->adj, 'V', 'W');

    mat_set_path(m->adj, 'W', 'V');
    mat_set_path(m->adj, 'W', 'X');

    mat_set_path(m->adj, 'X', 'W');
    mat_set_path(m->adj, 'X', 'Y');

    mat_set_path(m->adj, 'Y', 'T');
    mat_set_path(m->adj, 'Y', 'X');
}
