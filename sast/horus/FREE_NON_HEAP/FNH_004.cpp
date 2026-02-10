#include <stdlib.h>

/* FNH_004 - if branch2 */
void FNH_004_function(int arg) {
  int localValue = 0;
  int* heapValue = (int*)malloc(4);
  int* ptr = 0;
  if(arg == 10) {
    ptr = heapValue; //It's ok.
  }
  else {
    ptr = &localValue;
    free(heapValue);
  }

  free(ptr); //@violation FREE_NON_HEAP
  return; 
}
