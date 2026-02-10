/* DUL_002 - simple case, linux */

typedef void mtx_t;

extern int mtx_lock(mtx_t* mutex);
extern int mtx_unlock(mtx_t *mutex);

int DUL_002_function(mtx_t* mutex, int flag, int flag2) {
  mtx_lock(mutex);

  if(flag > 10) {
    if(flag2 == 100) {
      mtx_unlock(mutex); 
    }
  }

  mtx_unlock(mutex); //@violation DOUBLE_UNLOCK

  return 0;
}

