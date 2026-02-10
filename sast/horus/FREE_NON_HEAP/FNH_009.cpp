#include <stdlib.h>

/* FNH_009 - Function call, deep depth */
bool FNH_009_function1(bool flag, int* value) {
  if(flag == true) { 
    free(value); // FREE_NON_HEAP
    return true;
  }
  return false;
}


bool FNH_009_function2(int* value) {
  return FNH_009_function1(true, value); 
}

void FNH_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    FNH_009_function2(data1);
  }
  else{
    FNH_009_function2(data2); 
  }
}

int FNH_009_function4() {
  int* data1 = (int*)malloc(4);
  int data2 = 100;
  FNH_009_function3(true, data1, &data2); //It's ok. data1 is released.

  FNH_009_function3(false, data1, &data2); //@violation FREE_NON_HEAP
  
  return 0; 
}


