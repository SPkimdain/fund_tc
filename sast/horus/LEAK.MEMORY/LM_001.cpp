#include <stdlib.h>

/* LM_001 - Very simple null dereference. */
void LM_001_function() {
  int * ptr = (int*)malloc(4); 
} //@violation LEAK.MEMORY
