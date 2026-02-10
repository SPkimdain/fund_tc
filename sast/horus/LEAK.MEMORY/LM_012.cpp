#include <stdlib.h>

/* LM_012 - for */
void LM_012_function() {
  int* arr[3];
  int v = 10;
  
  arr[0] = (int*)malloc(sizeof(int));
  
  for(int i = 0; i < 3; i++) {
    if(i != 0) {
      arr[i] = &v;

      *arr[i] = 10;
    }    
  }
  
  //arr[0] is leak.
  return; 
} //@violation LEAK.MEMORY

