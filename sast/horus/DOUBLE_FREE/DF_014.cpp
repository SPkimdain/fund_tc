
#include <stdlib.h>

/* DF_014 - realloc() failed case. */
int* DF_014_function(int flag, int resize) {
  int* ptr = (int*)malloc(4 * sizeof(int));
  
  int* newPtr = (int*)realloc(ptr, resize * sizeof(int));
  
  if(newPtr == 0) {
    /* need to free. */
    free(ptr); //It's ok.
    return 0;
  }
  else {
    /* ptr is freed. */
    free(ptr); //@violation DOUBLE_FREE
    return newPtr;
  }  
  
}
