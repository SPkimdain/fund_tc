#include <stdlib.h>

void NDMF_002_function() {
  int* value = (int*)malloc(10);
  *value = 10; //@violation NULL_DEREF.MALLOC_FAILED
  
  free(value);
}

