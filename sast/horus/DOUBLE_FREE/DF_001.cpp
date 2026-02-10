#include <stdlib.h>

/* DF_001 - Very simple double free. */
int DF_001_function(int flag) {
  int * ptr = (int*)malloc(4); 
  free(ptr);
  free(ptr); //@violation DOUBLE_FREE
  return flag;
} 
