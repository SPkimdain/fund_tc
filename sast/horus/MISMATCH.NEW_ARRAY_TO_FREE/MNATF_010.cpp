#include <stdlib.h>

/* MNATF_010 - double pointer */
bool MNATF_010_function1(int** ptr){
  *ptr = new int[10];
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MNATF_010_function2(int** ptr){
  free(*ptr);
}


void MNATF_010_function3() {
  int* value = 0;
  bool ret = MNATF_010_function1(&value);

  MNATF_010_function2(&value); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

