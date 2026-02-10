#include <stdlib.h>

/* FNH_010 - multiple assign */
void FNH_010_function(int flag, int flag2) {
  int *ptr1 = (int*)malloc(4);

  if(ptr1 == 0) {
    return;
  }

  int *ptr2 = (int*)malloc(4);


  int ptr3 = 100;
  int* ptr = 0;
  
  *ptr1 = 10;
  *ptr2 = 20;
    
  ptr = ptr1;
  free(ptr); //It's ok.

  ptr = ptr2;
  free(ptr); //It's ok.

  ptr = &ptr3;
  free(ptr); //@violation FREE_NON_HEAP
  
}
