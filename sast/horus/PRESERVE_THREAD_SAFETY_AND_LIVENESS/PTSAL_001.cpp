
/* PTSAL_001 - simple case */

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
using cnd_t = void*;

extern int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
extern int thrd_join(thrd_t thr, int *res);

extern int mtx_init(mtx_t* mutex, int type);
extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);
extern void mtx_destroy(mtx_t *mutex);
extern int cnd_wait(cnd_t* cnd, mtx_t* mutex);
extern int cnd_init(cnd_t* cnd);
extern int cnd_signal(cnd_t* cnd);
extern int cnd_destroy(cnd_t* cnd);

enum { NTHREADS = 5 };

mtx_t mutex;
cnd_t cond;

int PTSAL_001_run_step(void *t) {
  static size_t current_step = 0;
  size_t my_step = *(size_t *)t;

  if(thrd_success != mtx_lock(&mutex)) {
    return 1;
  }

  while(current_step != my_step) {
    if(thrd_success != cnd_wait(&cond, &mutex)) {
      return 1;
    }
  }

  current_step++;

  if(thrd_success != cnd_signal(&cond)) { //@violation PRESERVE_THREAD_SAFETY_AND_LIVENESS
    return 1;
  }
  if(thrd_success != mtx_unlock(&mutex)) {
  }
  return 0;
}


int PTSAL_001_Function(void) {
  if(thrd_success != mtx_init(&mutex, 0)) {
    return 1;
  }

  if(thrd_success != cnd_init(&cond)) {
    return 1;
  }

  thrd_t* threads = new thrd_t[NTHREADS]();
  size_t* step = new size_t[NTHREADS]();

  for(size_t i = 0; i < NTHREADS; ++i) {
    step[i] = i;
    if(thrd_success != thrd_create(&threads[i], PTSAL_001_run_step, &step[i])) {
      delete[] threads;
      delete[] step;
      return 1;
    }
  }

  for(size_t i = NTHREADS; i != 0; --i) {
    if(thrd_success != thrd_join(threads[i - 1], 0)) {
      delete[] threads;
      delete[] step;
      return 1;
    }
  }

  mtx_destroy(&mutex);
  cnd_destroy(&cond);

  delete[] threads;
  delete[] step;
  
  return 0;
}
