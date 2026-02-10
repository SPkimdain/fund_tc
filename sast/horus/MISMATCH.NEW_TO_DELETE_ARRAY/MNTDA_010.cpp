#include <stdlib.h>

/* MNTDA_010 - double pointer */
bool MNTDA_010_function1(int** ptr){
  *ptr = new int(10);
  if(*ptr == 0) {
    return false;
  }
  return true;
}

void MNTDA_010_function2(int** ptr){
  delete[] *ptr;
}


void MNTDA_010_function3() {
  int* value = 0;
  bool ret = MNTDA_010_function1(&value);

  MNTDA_010_function2(&value); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

