#include <stdlib.h>

/* UAF_001 - simple use after free */
void UAF_001_function() {
  int * ptr = (int*)malloc(4);
  
  if(ptr == 0) {
    return;
  }

  free(ptr);
  *ptr = 1; //@violation USE_AFTER_FREE
  // memory allocated to ptr is leak
}
