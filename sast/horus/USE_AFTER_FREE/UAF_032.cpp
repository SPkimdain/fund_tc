#include <string.h>
#include <stdlib.h>

/* UAF_032 - memory function, memset */
void UAF_032_function1(int size) {
  char* buf = new char[size];
  if(buf == 0) {
    return;
  }

  memset(buf, 0, size);

  char* buf2 = new char[size];
  if(buf2 == 0) {
    delete[] buf;
    return;
  }

  delete[] buf2;

  memset(buf2, 0, size); //@violation USE_AFTER_FREE

  delete[] buf;
}
