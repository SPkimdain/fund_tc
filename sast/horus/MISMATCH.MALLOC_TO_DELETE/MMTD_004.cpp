#include <stdlib.h>

/* MMTD_004 - Call by value */
void MMTD_004_function1(char* src){
  delete src;
}

void MMTD_004_function2() {
  char* p = (char*)malloc(sizeof(char) * 10);

  MMTD_004_function1(p); //@violation MISMATCH.MALLOC_TO_DELETE
}

