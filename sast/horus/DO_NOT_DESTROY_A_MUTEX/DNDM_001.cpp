/* DNDM_001 - simple case, thrd_*, mtx_* */

#include <stdio.h>

enum {
  thrd_success,
  thrd_nomem,
  thrd_timedout,
  thrd_busy,
  thrd_error
};

using thrd_start_t = int(*)(void*);
using thrd_t = void*;
using mtx_t = void*;

extern int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
extern int thrd_join(thrd_t thr, int *res);

extern int mtx_init(mtx_t* mutex, int type);
extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);
extern void mtx_destroy(mtx_t *mutex);
mtx_t DNDM_001_lock;

enum DNDM_001_Enum { max_threads = 5 };

int DNDM_001_function(void* arg) {
  int *i = (int *)arg;

  if(*i == 0) { /* Creation thread */
    if(thrd_success != mtx_init(&DNDM_001_lock, 1)) {
      /* Handle error */
    }
  }
  else if(*i < max_threads - 1) { /* Worker thread */
    if(thrd_success != mtx_lock(&DNDM_001_lock)) {
      /* Handle error */
    }
    if(thrd_success != mtx_unlock(&DNDM_001_lock)) {
      /* Handle error */
    }
  }
  else { /* Destruction thread */
    mtx_destroy(&DNDM_001_lock); //@violation DO_NOT_DESTROY_A_MUTEX
  }
  return 0;
}

int DNDM_001_function2(void) {
  thrd_t threads[max_threads];
  static int index[max_threads] = { 0, };

  for(size_t i = 0; i < max_threads; i++) {
    index[i] = i;
    if(thrd_success != thrd_create(&threads[i], DNDM_001_function, &index[i])) {
      /* Handle error */
    }
  }
  for(size_t i = 0; i < max_threads; i++) {
    if(thrd_success != thrd_join(threads[i], 0)) {
      /* Handle error */
    }
  }
  return 0;
}
