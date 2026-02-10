#include <stdlib.h>

/* LM_009 - Function call, deep depth */
bool LM_009_function1(bool flag, int* value) {
  if(flag == true) {
    free(value);
    return true;
  }
  return false;
}


bool LM_009_function2(bool flag, int* value) {
  return LM_009_function1(flag, value); 
}

void LM_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    LM_009_function2(flag, data1);
  }
  else{
    LM_009_function2(flag, data2); 
  }
}

int LM_009_function4() {
  int* data1 = (int*)malloc(4);
  int* data2 = (int*)malloc(4);
  LM_009_function3(true, data1, data2); //It's ok. data1 is released.

  LM_009_function3(false, data1, data2); //data2 is not released.
  
  return 0;
} //@violation LEAK.MEMORY

