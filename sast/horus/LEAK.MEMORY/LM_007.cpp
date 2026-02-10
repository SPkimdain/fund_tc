#include <stdlib.h>

/* LM_007 - Function call, pointer parameter */
void LM_007_function1(int flag, int* arg) {
  if(flag == false) {
    free(arg);
  }
  
  return; //LEAK.MEMORY
}

void LM_007_function2() {
  int* ptr = (int*)malloc(4);
  LM_007_function1(false, ptr); //It's ok. ptr is released.

  ptr = (int*)malloc(5);
  LM_007_function1(true, ptr); 
}//@violation LEAK.MEMORY
