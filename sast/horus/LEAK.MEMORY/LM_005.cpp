#include <stdlib.h>

/* LM_005 - switch branch  */
void LM_005_function(int arg) {
  int x = 0;
  int* ptr = (int*)malloc(4);
  switch(arg) {
  case 0:
  case 1:
  case 2:
    x++; //This flow has a problem.
    break;
  case 3:
    free(ptr);
    break;
  default:
    free(ptr);
    break;
  }	

  return;
} //@violation LEAK.MEMORY
