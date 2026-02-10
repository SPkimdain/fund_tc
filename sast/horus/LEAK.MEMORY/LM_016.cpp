#include <stdlib.h>

/* LM_016 - Shift operator value */
void LM_016_function() {
  int value = 1;

  value = value << 2; // 4
  value = value >> 1; // 2

  int* ptr = (int*)malloc(4);
  
}//@violation LEAK.MEMORY
