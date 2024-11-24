#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "util.h"
#include "matrix.h"
#include "data_struct/stack.h"
#include "data_struct/queue.h"

int main() {
    struct timespec start, end;
    cell_t matrix[MAT_SIZE];
    position_t agent;

    matrix_init(matrix);
    print_matrix();

    // Starting time
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

#if defined(DFS)
    static const char *SEARCH_NAME = "DFS";
    stack_t stack;
    stack_init(&stack);
    stack_set(&stack, CHAR2INT(START_CELL));

    while (!stack_empty(&stack)) {
        agent.idx = stack_pop(&stack);
#elif defined(BFS)
    static const char *SEARCH_NAME = "BFS";
    queue_t queue;
    queue_init(&queue);
    queue_set(&queue, CHAR2INT(START_CELL));

    while (!queue_empty(&queue)) {
        agent.idx = queue_pop(&queue);
#endif
        agent.letter = INT2CHAR(agent.idx);

        // printf("Popping and checking cell %c...\n", agent.letter);

        if (agent.letter == GOAL_CELL) {
            break;
        }

        matrix[agent.idx].visited = true;

        for (int i = 0; i < MAT_SIZE; i++) {
            bool is_adjacent = matrix[agent.idx].adj_matrix[i];
            bool wasnt_visited = !matrix[i].visited;

            if (is_adjacent && wasnt_visited) {
                // printf("Adding cell %c to structure...\n", INT2CHAR(i));

#if defined(DFS)
                stack_set(&stack, i);
#elif defined(BFS)
                queue_set(&queue, i);
#endif

                // printf("%c is %c predecessor\n", agent.letter, INT2CHAR(i)); // rascunho
                matrix[i].predecessor = agent.idx;
            }
        }
    }

    // Finishing time
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    printf("--- %s ---\n", SEARCH_NAME);
    if (agent.letter == GOAL_CELL) {
        printf("Goal (%c cell) found\n", GOAL_CELL);
        matrix_print_path(matrix);
    } else {
        printf("Failed to find goal (%c cell)\n", GOAL_CELL);
    }
    printf("Time spent: %lld ns\n", delta_ns(start, end));

    size_t nodes_size;
#if defined(DFS)
    nodes_size = sizeof(node_t) * stack.nodes_allocated;
    stack_deinit(&stack);
#elif defined(BFS)
    nodes_size = sizeof(node_t) * queue.nodes_allocated;
    queue_deinit(&queue);
#endif
    printf("Memory spend with nodes allocated: %ld bytes\n", nodes_size);

    return 0;
}
