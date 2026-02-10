#include <stdlib.h>

/* LM_052 - loop. */
int* LM_052_function(int arg) {
  int * ptr = (int*)malloc(4);
  int * b = ptr;
  for (;;){
	  if (arg > 10){
		  free(ptr);
		  ptr = NULL;
	  }
	  break;
  }

  return ptr;
} //false positive alarm

void LM_052_function2() {
  int * ptr = (int*)malloc(4);
} //@violation LEAK.MEMORY
