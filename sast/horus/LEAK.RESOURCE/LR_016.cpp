#include <stdio.h>

/* LR_016 - Shift operator value */
void LR_016_function() {
  int value = 1;

  value = value << 2; // 4
  value = value >> 1; // 2

  FILE* file = fopen("test.txt", "w"); //It's ok. impossible path.

}//@violation LEAK.RESOURCE
