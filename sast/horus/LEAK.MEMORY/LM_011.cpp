#include <stdlib.h>

/* LM_011 - Complex call expression */
int LM_011_function1(bool flag, int* ptr) {
  if(flag == true) {
    free(ptr);
    return 0;
  }
  else {
    (*ptr)++;
    return *ptr;
  }
}

int LM_011_function2() {
  int value = 10;
  int value2 = 5;
  int *ptr = (int*)malloc(4 * sizeof(int));

  if(ptr == 0) {
    return 0;
  }

  int *ptr2 = (int*)malloc(4 * sizeof(int));

  if(ptr2 == 0) {
    free(ptr);
    return 0;
  }

  int ret = 0;

  *ptr = 10;
  *ptr2 = 10;

  ret = LM_011_function1(false, ptr) +
    LM_011_function1(true, ptr);
  //ptr is released.
    
  ret = LM_011_function1(false, ptr2) +
    LM_011_function1(false, ptr2) +
    LM_011_function1(false, ptr2);
  //ptr2 is not released.
     
  return ret; 
}// @violation LEAK.MEMORY
