#include <stdlib.h>

/* MNTF_002 - assign */
void MNTF_002_function(char* src, int flag){
  char* p = new char('x');
  
  char* ptr = 0;
  if(flag > 0) {
    ptr = src;
    delete p;
  }
  else {
    ptr = p; //This flow.
  }

  free(ptr);  //@violation MISMATCH.NEW_TO_FREE
}

