#include <stdio.h>

/* LR_009 - Function call, deep depth */
bool LR_009_function1(bool flag, FILE* value) {
  if(flag == true) {
    fclose(value);
    return true;
  }
  return false;
}


bool LR_009_function2(bool flag, FILE* value) {
  return LR_009_function1(flag, value); 
}

void LR_009_function3(bool flag, FILE* data1, FILE* data2) {
  if(flag == true) {
    LR_009_function2(flag, data1);
  }
  else{
    LR_009_function2(flag, data2); 
  }
}

int LR_009_function4(int value) {
  FILE* fp1 = fopen("test.txt", "r");
  FILE* fp2 = fopen("test2.txt", "r");
  
  LR_009_function3(true, fp1, fp2); //It's ok. data1 is released.
  LR_009_function3(false, 0, fp2); //data2 is not released.
  
  return 0;
} //@violation LEAK.RESOURCE

