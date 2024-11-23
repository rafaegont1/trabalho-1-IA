#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <time.h>
// #include <sys/resource.h>

typedef struct {
    char name[32];
    void *self;
    bool (*empty)(void *);
    void (*init)(void *);
    void (*deinit)(void *);
    void (*set)(void *, char);
    char (*pop)(void *);
} data_struct_t;

// typedef struct {
//     struct rusage r_usage;
//     long before;
//     long after;
// } mem_usage_t;

// typedef struct {
//     clock_t begin;
//     clock_t end;
// } time_spend_t;

// double get_time_spend(const time_spend_t *time);
long long delta_ns(const struct timespec start, const struct timespec end);
// long get_mem_usage(mem_usage_t *mem);

#endif // UTIL_H
