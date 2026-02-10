#include <stdlib.h>

/* DF_005 - assign pointer */
void DF_005_function() {
  int* ptr = (int*)malloc(4);
  int* ptr2 = ptr;
  free(ptr2);
  free(ptr); //@violation DOUBLE_FREE
}

