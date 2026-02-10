#include <stdlib.h>

/* UAF_002 - assign a pointer. */
void UAF_002_function() {
  int* ptr = (int*)malloc(4);
  
  if(ptr == 0) {
    return;
  }

  int* adp = ptr;
  free(adp);
  *ptr = 1; //@violation USE_AFTER_FREE
}

