#include <stdlib.h>

/* MNATF_004 - Call by value */
void MNATF_004_function1(char* src){
  free(src);
}

void MNATF_004_function2() {
  char* p = new char[10];

  MNATF_004_function1(p); //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

