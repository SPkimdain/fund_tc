/* DNDM_002 - simple case2, * / mtx_* */

#include <stdio.h>

enum {
  thrd_success,
  thrd_nomem,
  thrd_timedout,
  thrd_busy,
  thrd_error
};

using thrd_start_t = int(*)(void*);
using mtx_t = void*;

using HANDLE = void*;

extern HANDLE CreateThread(
  void* lpThreadAttributes, // Security Descriptor
  unsigned dwStackSize, // initial stack size
  thrd_start_t lpStartAddress, // thread function
  void* lpParameter, // thread argument
  unsigned dwCreateionFlags, // thread identifier
  unsigned* lpThreadId // thread identifier
  );

extern int mtx_init(mtx_t* mutex, int type);
extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);
extern void mtx_destroy(mtx_t *mutex);
mtx_t DNDM_002_lock;

enum DNDM_002_Enum { max_threads = 5 };

void DNDM_002_mutex_destroy() {
  mtx_destroy(&DNDM_002_lock);
}

int DNDM_002_function(void* arg) {
  int *i = (int *)arg;

  if(*i == 0) { /* Creation thread */
    if(thrd_success != mtx_init(&DNDM_002_lock, 1)) {
      /* Handle error */
    }
  }
  else if(*i < max_threads - 1) { /* Worker thread */
    if(thrd_success != mtx_lock(&DNDM_002_lock)) {
      /* Handle error */
    }
    if(thrd_success != mtx_unlock(&DNDM_002_lock)) {
      /* Handle error */
    }
  }
  else { /* Destruction thread */
    DNDM_002_mutex_destroy(); //@violation DO_NOT_DESTROY_A_MUTEX
  }
  return 0;
}

int DNDM_002_function2(void) {
  unsigned id = 0;
  static int index = 10;
  CreateThread(0, 0, DNDM_002_function, (void*)&index, 0, &id);

  return 0;
}
