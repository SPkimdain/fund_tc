/* DOSBT_001 - simple case */

enum {
  thrd_success,
  thrd_nomem,
  thrd_timedout,
  thrd_busy,
  thrd_error
};

using thrd_start_t = int(*)(void*);
using thrd_t = void*;

extern int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
extern int thrd_join(thrd_t thr, int *res);


int DOSBT_001_thread(void *val) {
  int *res = (int *)val;
  return 0;
}

int DOSBT_001_Create(thrd_t *tid) {
  int val = 1;
  if(thrd_success != thrd_create(tid, DOSBT_001_thread, &val)) { //@violation DECLARE_OBJECTS_SHARED_BETWEEN_THREADS
    /* Handle error */
    return -1;
  }
  return 0;
}

int DOSBT_001_Function(void) {
  thrd_t tid;
  DOSBT_001_Create(&tid);

  if(thrd_success != thrd_join(tid, 0)) {
    /* Handle error */
    return -1;
  }
  return 0;
}
