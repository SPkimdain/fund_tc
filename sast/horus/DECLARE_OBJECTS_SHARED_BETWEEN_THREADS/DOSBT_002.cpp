/* DOSBT_002 - simple case2 */

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


int DOSBT_002_Thread(void *val) {
  int *result = (int *)val;
  return 0;
}

int DOSBT_002_Create(thrd_t *tid, int *val) {
  if(thrd_success != thrd_create(tid, DOSBT_002_Thread, val)) {
    /* Handle error */
    return -1;
  }
  return 0;
}

int DOSBT_002_Function(void) {
  int val = 1;
  thrd_t tid;
  DOSBT_002_Create(&tid, &val); //@violation DECLARE_OBJECTS_SHARED_BETWEEN_THREADS
  if(thrd_success != thrd_join(tid, 0)) {
    /* Handle error */
    return -1;
  }
  return 0;
}

