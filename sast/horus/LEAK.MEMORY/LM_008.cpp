#include <stdlib.h>

/* LM_008 - Function call, return value */
int* LM_008_function1() {
  return (int*)malloc(4);
}

void LM_008_function2() {
  int* ptr = LM_008_function1();
  int* ptr2 = LM_008_function1();

  free(ptr);

  return; //LEAK.MEMORY
  //ptr2 leak.
}//@violation LEAK.MEMORY
