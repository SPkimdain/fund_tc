#include <stdlib.h>

/* MNTF_004 - Call by value */
void MNTF_004_function1(char* src){
  free(src);
}

void MNTF_004_function2() {
  char* p = new char('a');

  MNTF_004_function1(p); //@violation MISMATCH.NEW_TO_FREE
}

