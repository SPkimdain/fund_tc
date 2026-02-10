#include <stdlib.h>

/* MNTDA_006 - Call by reference */
void MNTDA_006_function1(int* src){
  delete[] src;
}

bool MNTDA_006_function2(int*& ptr) {
  ptr = new int[10]; //Array.
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MNTDA_006_function3(int*& ptr) {
  ptr = new int(10); //Value.
  if(ptr != 0){
    return true;
  }
  return false;
}

void MNTDA_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MNTDA_006_function2(value); //It's ok. new[] allocation.
  }
  else {
    MNTDA_006_function3(value); //It's a problem. new allocation.
  }

  MNTDA_006_function1(value); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

