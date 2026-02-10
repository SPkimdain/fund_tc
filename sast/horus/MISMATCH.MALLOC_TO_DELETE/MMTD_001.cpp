#include <stdlib.h>

/* MMTD_001 - simple case */
void MMTD_001_function(){
  char *p = (char*)malloc(10);
  delete p;  //@violation MISMATCH.MALLOC_TO_DELETE
}

