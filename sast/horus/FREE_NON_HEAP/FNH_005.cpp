#include <stdlib.h>

/* FNH_005 - switch branch  */
void FNH_005_function(int arg) {
  int localValue = 10;
  int* heapValue = (int*)malloc(4);
  
  if(heapValue == 0) {
    return;
  }

  *heapValue = 10;
  int* ptr = heapValue;
  switch(arg) {
  case 0:
  case 1:
  case 2:
    ptr = &localValue; //This flow has a problem.
    free(heapValue); //It's ok.
    free(ptr); //@violation FREE_NON_HEAP
    break;
  case 3:
    free(ptr);
    break;
  default:
    free(ptr);
    break;
  }

  return; 
}
