#include <stdlib.h>

/* MNATF_006 - Call by reference */
void MNATF_006_function1(int* src){
  free(src);
}

bool MNATF_006_function2(int*& ptr) {
  ptr = (int*)malloc(sizeof(int) *10);
  if(ptr != 0) {
    return true;
  }
  return false;
}

bool MNATF_006_function3(int*& ptr) {
  ptr = new int[10];
  if(ptr != 0){
    return true;
  }
  return false;
}

void MNATF_006_function4(int flag) {
  int* value = 0;

  if(flag > 0) {
    MNATF_006_function2(value); //It's ok. malloc allocation.
  }
  else {
    MNATF_006_function3(value); //It's a problem. new[] allocation.
  }

  MNATF_006_function1(value); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

