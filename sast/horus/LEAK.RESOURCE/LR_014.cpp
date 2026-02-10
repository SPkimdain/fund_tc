#include <stdio.h>

/* LR_014 - call by reference */
void LR_014_function1(FILE** ptr, FILE** ptr2) {
  *ptr = fopen("log1.txt", "w");
  *ptr2 = fopen("log2.txt", "r");
}

FILE* LR_014_function2() {
  int data = 10;

  FILE* file = 0;
  FILE* file2 = 0;

  LR_014_function1(&file, &file2);

  return file;
  //file2 is leaked.
} //@violation LEAK.RESOURCE

