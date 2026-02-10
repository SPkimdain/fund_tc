#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void f(pthread_mutex_t *count_mutex, pthread_cond_t *count_threshold_cv)
{
    pthread_mutex_lock(count_mutex); //@violation
    // critical section

    // Signal waiting thread



}