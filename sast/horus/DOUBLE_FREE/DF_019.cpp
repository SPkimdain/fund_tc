
#include <stdlib.h>

/* DF_019 - realloc double free. */
int DF_019_function(int size, int flag) {
  int* ptr = (int*)malloc(size * sizeof(int));
  if(flag > 10) {
    free(ptr);
  }

  int* ptr2 = (int*) realloc(ptr, size * 2 * sizeof(int)); //@violation DOUBLE_FREE
  if(ptr2 == 0 && flag <= 10) {
    /* need to free if realloc is failed. */
    free(ptr);
  }

  free(ptr2);
  return 1;
}

