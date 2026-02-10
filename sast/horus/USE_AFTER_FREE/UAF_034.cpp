#include <string.h>
#include <stdlib.h>

/* UAF_034 - memory function, strncpy */
void UAF_034_function(char* src, int flag) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  int size = strlen(src);

  if(flag == 0) {
    delete[] buf;
    /* Wrong control flow */
    //return;
  }

  strncpy(buf, src, size); //@violation USE_AFTER_FREE
  
  if(flag != 0) {
    delete[] buf;
  }
}

