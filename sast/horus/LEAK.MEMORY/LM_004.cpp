#include <stdlib.h>

/* LM_004 - if branch2 */
void LM_004_function(int arg) {
  int* ptr1 = (int*)malloc(4);
  
  if(ptr1 == 0) {
    return;
  }

  if(arg == 10) {
    free(ptr1);
  }
  else {
    *ptr1 = 1;
  }

  return; 
} //@violation LEAK.MEMORY
