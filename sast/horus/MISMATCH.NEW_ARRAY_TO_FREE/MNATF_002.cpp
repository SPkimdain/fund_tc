#include <stdlib.h>

/* MNATF_002 - assign */
void MNATF_002_function(char* src, int flag){
  char* p = new char[10];
  
  char* ptr = 0;
  if(flag > 0) {
    ptr = src;
    delete[] p;
  }
  else {
    ptr = p; //This flow.
  }

  free(ptr);  //@violation MISMATCH.NEW_ARRAY_TO_FREE
}

