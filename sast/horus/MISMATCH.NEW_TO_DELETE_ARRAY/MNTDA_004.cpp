#include <stdlib.h>

/* MNTDA_004 - Call by value */
void MNTDA_004_function1(char* src){
  delete[] src;
}

void MNTDA_004_function2() {
  char* p = new char('a');

  MNTDA_004_function1(p); //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

