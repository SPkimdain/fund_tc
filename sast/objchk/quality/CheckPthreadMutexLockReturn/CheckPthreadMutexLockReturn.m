void foo(pthread_mutex_t *mutex) {
     pthread_mutex_lock(mutex); //@violation

     /* access shared resource */

     pthread_mutex_unlock(mutex);
 }