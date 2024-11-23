#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

#define MAT_SIZE 25

#define CELL_IDX(x) ((x) - 'A')
#define CELL_NAME(x) ((x) + 'A')
#define ADJ_MAT_IDX(src, dst) (MAT_SIZE * (src) + (dst))

typedef struct matrix_s matrix_t;
typedef struct player_s player_t;

struct matrix_s {
    bool adj[MAT_SIZE * MAT_SIZE]; // adjacency matrix
    bool vis[MAT_SIZE]; // visited cells
    // char curr; // current cell
};

// struct player_s {
//     char pos;
// };

void mat_init(matrix_t *m);
void mat_set_path(bool *mat, char src, char dst);
bool mat_get_path(bool *mat, char src, char dst);

#endif // MATRIX_H
