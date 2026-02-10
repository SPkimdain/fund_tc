#include <stdio.h>

/* LR_011 - Complex call expression */
int LR_011_function1(bool flag, FILE* fp) {
  if(flag == true) {
    fclose(fp);
    return 0;
  }
  else {
    return 1;
  }
}

int LR_011_function2() {
  int value = 10;
  int value2 = 5;
  FILE* file = fopen("test.txt", "w");

  if(file == 0) {
    return 0;
  }

  FILE* file2 = fopen("test123.txt", "w");

  if(file2 == 0) {
    fclose(file);
    return 0;
  }

  int ret = 0;

  ret = LR_011_function1(false, file) +
    LR_011_function1(true, file);
  //file is released.
    
  ret = LR_011_function1(false, file2) +
    LR_011_function1(false, file2) +
    LR_011_function1(false, file2);
  //file2 is not released.
     
  return ret; 
}// @violation LEAK.RESOURCE
