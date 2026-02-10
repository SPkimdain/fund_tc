#include <stdlib.h>

/* MNATD_004 - Call by value */
void MNATD_004_function1(char* src){
  delete src;
}

void MNATD_004_function2() {
  char* p = new char[10];

  MNATD_004_function1(p); //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}

