#include <stdlib.h>

/* MNTF_006 - Call by reference */
void MNTF_006_function1(int* src){
  free(src);
}

bool MNTF_006_function2(int*& ptr) {
  ptr = (int*)malloc(sizeof(int) * 10);
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MNTF_006_function3(int*& ptr) {
  ptr = new int(10); //Value.
  if(ptr != 0){
    return true;
  }
  return false;
}

void MNTF_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MNTF_006_function2(value); //It's ok. new[] allocation.
  }
  else {
    MNTF_006_function3(value); //It's a problem. new allocation.
  }

  MNTF_006_function1(value); //@violation MISMATCH.NEW_TO_FREE
}

