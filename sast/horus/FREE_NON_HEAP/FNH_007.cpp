#include <stdlib.h>

/* FNH_007 - Function call, pointer parameter */
void FNH_007_function1(int flag, int* arg) {
  if(flag == false) {
    free(arg); // FREE_NON_HEAP
  }
  
  return; 
}

void FNH_007_function2() {
  int* ptr = (int*)malloc(4);
  FNH_007_function1(false, ptr); //It's ok. ptr is heap value;

  int value = 0;
  FNH_007_function1(false, &value); //@violation FREE_NON_HEAP
}
