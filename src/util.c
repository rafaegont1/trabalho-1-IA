#include "util.h"

// double get_time_spend(const time_spend_t *time) {
//     double time_spent = (double)(time->end - time->begin) / CLOCKS_PER_SEC;

//     return time_spent;
// }

long long delta_ns(const struct timespec start, const struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
}

// long get_mem_usage(mem_usage_t *mem) {
//     long usage;

//     getrusage(RUSAGE_SELF,&mem->r_usage);
//     usage = mem->r_usage.ru_maxrss;

//     return usage;
// }
