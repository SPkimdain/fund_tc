#include <stdlib.h>

/* LM_060 - allocate/deallocate with a loop */

int LM_060_function1() {
  int* arr[5];
  
  for(int i = 0; i < 5; i++) {
    arr[i] = (int*)malloc(10 * sizeof(int));
    if(arr[i] == 0) {
      return 1;
    }
  }
  
  /*if(arr[0] == 0) {
    return 1;
  }*/
  
  arr[0][5] = 10;
  
  for(int j = 0; j < 5; j++) {
    free(arr[j]);
  }

  return i + j;
} //It's ok.


void LM_060_function2() {
  int * ptr = (int*)malloc(4); 
} //@violation LEAK.MEMORY

