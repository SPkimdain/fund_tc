#include <stdlib.h>

/* LM_002 - assign a pointer. */
void LM_002_function() {
  int* ptr = (int*)malloc(4);
  int* ptr2 = ptr;
  ptr = 0;  
} //@violation LEAK.MEMORY
