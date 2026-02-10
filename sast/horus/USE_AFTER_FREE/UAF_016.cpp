#include <stdlib.h>

/* UAF_016 - Shift operator value */
void UAF_016_function() {
  int value = 1;
  int* ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  int ret = 0;
  *ptr = 100;

  value = value << 2; // value == 4
  value = value >> 1; // value == 2

  free(ptr);
  
  ret = *ptr; //@violation USE_AFTER_FREE
}
