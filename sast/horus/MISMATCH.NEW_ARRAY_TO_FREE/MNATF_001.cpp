#include <stdlib.h>

void MNATF_001_function(){
  char *p = new char[10];
  free(p);  //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

