#include <stdio.h>

/* LR_018 - missing pointer */
void LR_018_function() {
  FILE* file = fopen("test.txt", "w");
  
  file = 0;
  
  fclose(file); //Undefined behavior.
} //@violation LEAK.RESOURCE

