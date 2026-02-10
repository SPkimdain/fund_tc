#include <string.h>
#include <stdlib.h>

/* UAF_031 - memory function, memcpy */
void UAF_031_function(char* str, int size) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  memcpy(buf, str, size);

  char* buf2 = new char[256];
  if(buf2 == 0) {
    delete[] buf;
    return;
  }

  delete[] buf2;

  memcpy(buf2, str, size); //@violation USE_AFTER_FREE

  delete[] buf;
}

