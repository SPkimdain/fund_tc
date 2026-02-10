#include <stdlib.h>

void MMTDA_001_function(){
  char *p = (char*)malloc(10);
  delete[] p;  //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY
}

