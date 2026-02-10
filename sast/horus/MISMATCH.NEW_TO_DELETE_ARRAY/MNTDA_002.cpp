#include <stdlib.h>

/* MNTDA_002 - assign */
void MNTDA_002_function(char* src, int flag){
  char* p = new char('x');
  
  char* ptr = 0;
  if(flag > 0) {
    ptr = src;
    delete p;
  }
  else {
    ptr = p; //This flow.
  }

  delete[] ptr;  //@violation MISMATCH.NEW_TO_DELETE_ARRAY
}

