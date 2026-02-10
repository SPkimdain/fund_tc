#include <stdio.h>

/* LR_002 - assign a pointer. */
void LR_002_function() {
  FILE* fp = fopen("test.txt", "r");
  FILE* fp2 = fp;
  fp = 0;
} //@violation LEAK.RESOURCE
