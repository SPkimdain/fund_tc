#include <stdlib.h>

/* MMTDA_006 - Call by reference */
void MMTDA_006_function1(int* src){
  delete[] src;
}

bool MMTDA_006_function2(int*& ptr) {
  ptr = new int[10];
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MMTDA_006_function3(int*& ptr) {
  ptr = (int*)malloc(10);
  if(ptr != 0){
    return true;
  }
  return false;
}

void MMTDA_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MMTDA_006_function2(value); //It's ok. new allocation.
  }
  else {
    MMTDA_006_function3(value); //It's a problem. malloc allocation.
  }

  MMTDA_006_function1(value); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}

