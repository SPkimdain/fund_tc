#include <stdlib.h>

/* MMTDA_004 - Call by value */
void MMTDA_004_function1(char* src){
  delete[] src;
}

void MMTDA_004_function2() {
  char* p = (char*)malloc(sizeof(char) * 10);

  MMTDA_004_function1(p); //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}

