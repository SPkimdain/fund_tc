
/* PDR_002 - simple case2 */

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
mtx_t PDR_002_lock;

enum PDR_002_Enum { max_threads = 5 };

struct PDR_002_Multi_threaded_flags {
  unsigned int flag1 : 2;
  unsigned int flag2 : 2;
};

struct PDR_002_mtf_mutex {
  struct PDR_002_Multi_threaded_flags s;
  mtx_t mutex;
};

struct PDR_002_mtf_mutex flags;

int PDR_002_lock_function() {
  return mtx_lock(&flags.mutex);
}

int PDR_002_unlock_function() {
  return mtx_unlock(&flags.mutex);
}


int PDR_002_funciton1(void *arg) {
  if(thrd_success != PDR_002_lock_function()) {
    /* Handle error */
  }

  flags.s.flag1 = 1; //It's ok.

  if(thrd_success != PDR_002_unlock_function()) {
    /* Handle error */
  }

  return 0;
}

int PDR_002_funciton2(void *arg) {
  flags.s.flag1 = 1; //@violation PREVENT_DATA_RACES
  return 0;
}

int PDR_002_function3() {
  thrd_t thread1;
  thrd_t thread2;

  if(thrd_success != thrd_create(&thread1, PDR_002_funciton1, 0)) {
    /* Handle error */
    return -1;
  }

  if(thrd_success != thrd_create(&thread1, PDR_002_funciton2, 0)) {
    /* Handle error */
    return -1;
  }

  return 0;
}
