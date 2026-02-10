#include <memory.h>

void MNTDA_001_function(){
  char *p = new char;
  delete []p;  //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

