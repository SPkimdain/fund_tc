#include <stdlib.h>

/* FNH_002 - assign a pointer. */
void FNH_002_function() {
  int value = 10;
  int* ptr = &value;
  free(ptr); //@violation FREE_NON_HEAP
} 
