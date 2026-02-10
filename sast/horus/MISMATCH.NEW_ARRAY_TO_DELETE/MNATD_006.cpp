#include <stdlib.h>

/* MNATD_006 - Call by reference */
void MNATD_006_function1(int* src){
  delete src;
}

bool MNATD_006_function2(int*& ptr) {
  ptr = new int(10);
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MNATD_006_function3(int*& ptr) {
  ptr = new int[10];
  if(ptr != 0){
    return true;
  }
  return false;
}

void MNATD_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MNATD_006_function2(value); //It's ok. new allocation.
  }
  else {
    MNATD_006_function3(value); //It's a problem. new[] allocation.
  }

  MNATD_006_function1(value); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}

