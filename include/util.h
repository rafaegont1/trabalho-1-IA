#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <time.h>

#define MAT_SIZE 25
#define START_CELL 'U'
#define GOAL_CELL 'E'

#define CHAR2INT(x) ((x) - 'A')
#define INT2CHAR(x) ((x) + 'A')

typedef struct {
    char letter;
    int idx;
} position_t;

long long delta_ns(const struct timespec start, const struct timespec end);
void print_matrix();
// void print_path(const char *predecessor);

#endif // UTIL_H
