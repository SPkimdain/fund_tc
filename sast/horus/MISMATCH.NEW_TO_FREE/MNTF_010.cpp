#include <stdlib.h>

/* MNTF_010 - double pointer */
bool MNTF_010_function1(int** ptr){
  *ptr = new int(10);
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MNTF_010_function2(int** ptr){
  free(*ptr);
}


void MNTF_010_function3() {
  int* value = 0;
  bool ret = MNTF_010_function1(&value);

  MNTF_010_function2(&value); //@violation MISMATCH.NEW_TO_FREE
}

