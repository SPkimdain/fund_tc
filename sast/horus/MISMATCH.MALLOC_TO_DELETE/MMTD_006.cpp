#include <stdlib.h>

/* MMTD_006 - Call by reference */
void MMTD_006_function1(int* src){
  delete src;
}

bool MMTD_006_function2(int*& ptr) {
  ptr = new int(10);
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MMTD_006_function3(int*& ptr) {
  ptr = (int*)malloc(10);
  if(ptr != 0){
    return true;
  }
  return false;
}

void MMTD_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MMTD_006_function2(value); //It's ok. new allocation.
  }
  else {
    MMTD_006_function3(value); //It's a problem. malloc allocation.
  }

  MMTD_006_function1(value); //@violation MISMATCH.MALLOC_TO_DELETE
}

