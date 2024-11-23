#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "queue.h"
#include "matrix.h"
#include "util.h"

#define START_CELL 'U'
#define GOAL_CELL 'E'

typedef struct {
    char letter;
    int idx;
} position_t;

void uninformed_search(matrix_t *m, FILE *fp);
void print_matrix();

int main() {
    FILE *fp;
    matrix_t m;

    print_matrix();

#if defined(DFS)
    fp = fopen("log_dfs.txt", "w");
#elif defined(BFS)
    fp = fopen("log_bfs.txt", "w");
#endif
    if (fp == NULL) {
        fprintf(stderr, "It wasn't possible to create the log file\n");
        exit(EXIT_FAILURE);
    }

    mat_init(&m);
    uninformed_search(&m, fp);

    fclose(fp);
    return 0;
}

void uninformed_search(matrix_t *m, FILE *fp) {
    struct timespec start, end;
    position_t agent;
    
    // Matriz para armazenar os predecessores de cada célula
    char predecessor[MAT_SIZE] = {0};

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

#if defined(DFS)
    static const char *SEARCH_NAME = "DFS";
    stack_t stack;
    stack_init(&stack);
    stack_set(&stack, START_CELL); // Inicia a pilha com a célula de início
#elif defined(BFS)
    static const char *SEARCH_NAME = "BFS";
    queue_t queue;
    queue_init(&queue);
    queue_set(&queue, START_CELL); // Inicia a fila com a célula de início
#endif

    // Log do tipo de busca
    fprintf(fp, "____________________%s____________________\n", SEARCH_NAME);

#if defined(DFS)
    while (!stack_empty(&stack)) {
        agent.letter = stack_pop(&stack);
#elif defined(BFS)
    while (!queue_empty(&queue)) {
        agent.letter = queue_pop(&queue);
#endif
        agent.idx = CELL_IDX(agent.letter);

        fprintf(fp, "Checking cell %c...\n", agent.letter);

        // Verifica se chegou na célula objetivo
        if (agent.letter == GOAL_CELL) {
            break;
        }

        m->vis[agent.idx] = true; // Marca a célula como visitada

        // Verifica as células vizinhas e as adiciona à estrutura de dados
        for (position_t iter = { .idx = 0 }; iter.idx < MAT_SIZE; iter.idx++) {
            iter.letter = CELL_NAME(iter.idx);

            // Se a célula vizinha não foi visitada e é adjacente, adicione à estrutura de dados
            if (!m->vis[iter.idx] && mat_get_path(m->adj, agent.letter, iter.letter)) {
                fprintf(fp, "Adding cell %c to structure...\n", iter.letter);

#if defined(DFS)
                stack_set(&stack, iter.letter);
#elif defined(BFS)
                queue_set(&queue, iter.letter);
#endif
                // Armazena o predecessor de cada célula para reconstrução do caminho
                predecessor[iter.idx] = agent.letter;
            }
        }
    }

    // Verifica se encontrou o objetivo
    printf("--- %s ---\n", SEARCH_NAME);
    if (agent.letter == GOAL_CELL) {
        for (int i = 0; i < MAT_SIZE; i++) { // rascunho
            printf("%c > ", predecessor[i]); // rascunho
        } // rascunho
        printf("\n"); // rascunho

        printf("Goal (%c cell) found\n", GOAL_CELL);

        // Reconstruir o caminho
        printf("Reconstructing path...\n");
        char path[MAT_SIZE]; // Para armazenar o caminho final
        int path_idx = 0;
        char current = GOAL_CELL;

        // Reconstrução do caminho a partir do objetivo até o início
        while (current != START_CELL) {
            path[path_idx++] = current;
            current = predecessor[CELL_IDX(current)]; // Move para o predecessor
        }

        // Adiciona a célula de início ao caminho
        path[path_idx++] = START_CELL;

        // Exibe e salva o caminho no log
        fprintf(fp, "Path found: ");
        for (int i = path_idx - 1; i >= 0; i--) {
            fprintf(fp, "%c ", path[i]);
        }
        fprintf(fp, "\n");

    } else {
        printf("Failed to find goal (%c cell)\n", GOAL_CELL);
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time spent: %lld ns\n", delta_ns(start, end));
    size_t nodes_allocated;

#if defined(DFS)
    nodes_allocated = sizeof(stack_node_t) * stack.nodes_allocated;
    stack_deinit(&stack); // Finaliza a pilha
#elif defined(BFS)
    nodes_allocated = sizeof(queue_node_t) * queue.nodes_allocated;
    queue_deinit(&queue); // Finaliza a fila
#endif

    printf("Memory spend with nodes allocated: %ld bytes\n", nodes_allocated);
}

void print_matrix() {
    printf("Input matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Ajuste para imprimir apenas A-Z
            printf("%c ", ((5 * i + j) % 26) + 'A');
        }
        printf("\n");
    }
}
