#include <stdlib.h>

/* MNTF_003 - complex flow */
void MNTF_003_function(char* src, int kind, int flag, int flag2){
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

  free(p);  //@violation MISMATCH.NEW_TO_FREE
}

