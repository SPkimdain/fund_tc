#include <stdlib.h>

/* LM_010 - multiple return */
void LM_010_function(int flag, int flag2) {
  int *ptr1 = (int*)malloc(4);

  if(ptr1 == 0) {
    return;
  }

  int *ptr2 = (int*)malloc(4);

  if(ptr2 == 0) {
    free(ptr1);
    return;
  }

  int *ptr3 = (int*)malloc(6);

  if(ptr3 == 0) {
    free(ptr1);
    free(ptr2);
    return;
  }
  
  *ptr1 = 10;
  *ptr2 = 20;
  *ptr3 = 30;

  free(ptr3); //ptr3 is released.

  if(flag > 10) {
    free(ptr2); //ptr2 is released.
    if(flag2){
      free(ptr1); //ptr1 is released.
      return; //It's ok.
    }
    else {
      //ptr1 is not released.
      return;
    } //@violation LEAK.MEMORY
  }
  else {
    free(ptr2); //ptr2 is released.
    free(ptr1); //ptr1 is released.
    return; //It's ok.
  }
}
