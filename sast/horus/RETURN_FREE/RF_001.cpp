#include <stdlib.h>

/* RF_001 - Very simple return free. */
int* RF_001_function() {
  int * ptr = (int*)malloc(4); 
  free(ptr);
  return ptr; //@violation RETURN_FREE
} 
