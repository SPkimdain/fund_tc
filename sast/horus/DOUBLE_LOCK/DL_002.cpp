/* DL_002 - simple case, linux */

typedef void mtx_t;

extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);

int DL_002_function(mtx_t* mutex, int flag, int flag2) {
  mtx_lock(mutex);

  if(flag > 10) {
    if(flag2 == 100) {
      mtx_lock(mutex); //@violation DOUBLE_LOCK
    }
  }  

  mtx_unlock(mutex);

  return 0;
}

