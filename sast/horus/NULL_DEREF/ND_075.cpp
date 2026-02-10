#include <stdlib.h>
#include <string.h>


/* ND_075 - memset dereference test. */
int* ND_075_function(int size) {
  int* ptr = 0;
  if(size > 0) {
    ptr = (int*)calloc(size, sizeof(int));
    if(ptr == 0) {
      return 0;
    }
  }
  
  memset(ptr, 0, size * sizeof(int)); //@violation NULL_DEREF

  return ptr;
}
