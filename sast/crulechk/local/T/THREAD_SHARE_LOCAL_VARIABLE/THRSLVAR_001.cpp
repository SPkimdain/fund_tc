//@checker THREAD_SHARE_LOCAL_VARIABLE
#include "THRSLVAR_001.h"
#include <stdio.h>

void* THRSLVAR_001_thread(void *val) {
  /*
   * Depending on the order of thread execution, the object
   * referred to by val may be out of its lifetime, resulting
   * in a potentially incorrect result being printed out.
   */
  int *res = (int *)val;
  //printf("Result: %d\n", *res);
  return NULL;
}


void THRSLVAR_001_function(pthread_t *tid) {
  /* Store 1 in val on the stack. */
  int val = 1;
  int result;
  if ((result = pthread_create(tid, NULL, THRSLVAR_001_thread, &val)) != 0) { //@violation THREAD_SHARE_LOCAL_VARIABLE
    /* Handle error */
  }
}
 