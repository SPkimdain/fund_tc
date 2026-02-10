#include <stdlib.h>

/* MNTDA_003 - complex flow */
void MNTDA_003_function(char* src, int kind, int flag, int flag2){
  char *p = new char('a');
  char* ptr = 0;

  switch(kind) {
  case 0:
  case 1:
  case 2:
  case 3:
    if(flag > 0 && flag2 == 10) {
      ptr = p;
    }
    break;
  default:
    break;
  }

  if(ptr == 0) {
    ptr = src;
  }

  delete[] p;  //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

