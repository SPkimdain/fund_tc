#include <string.h>
#include <stdlib.h>

/* UAF_040 - memory function, strncpy, multiple */
void UAF_040_function1(char* src, char* dst, int size) {
  strncpy(dst, src, size);
}

void UAF_040_function2(char* src, int flag) {
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

  UAF_040_function1(src, buf, size); //@violation USE_AFTER_FREE
  
  if(flag != 0) {
    delete[] buf;
  }
}


