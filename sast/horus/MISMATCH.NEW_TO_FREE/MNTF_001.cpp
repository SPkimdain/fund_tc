#include <stdlib.h>

void MNTF_001_function(){
  char *p = new char;
  free(p);  //@violation MISMATCH.NEW_TO_FREE
}

