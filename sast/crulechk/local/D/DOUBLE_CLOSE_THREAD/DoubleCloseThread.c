//@checker DOUBLE_CLOSE_THREAD
  
typedef int thrd_t;
  
  
extern void thrd_detach(int*);
extern int* thrd_current();
extern int thread_func(void*);
extern int thrd_create(int *t,int (*fp)(void*),void*);
extern int thrd_join(thrd_t t, int val);
  
int thread_func(void *arg) 
{
  /* Do work */
  thrd_detach(thrd_current());
  return 0;
}
 
int DBLCLSTHRD_001_function(void) 
{
  thrd_t t,t2;
  int thrd_success;
 
  if (thrd_success != thrd_create(&t, thread_func, 0)) {
    /* Handle error */
    return 0;
  }
 
   if (thrd_success != thrd_create(&t2, thread_func, 0)) {
    /* Handle error */
    return 0;
  }
 


  if (thrd_success != thrd_join(t, 0)) { //@violation DOUBLE_CLOSE_THREAD
    /* Handle error */
    return 0;
  }

  

  if (thrd_success != thrd_join(t2, 0)) { //@violation DOUBLE_CLOSE_THREAD
    /* Handle error */
    return 0;
  }

  return 0;
}