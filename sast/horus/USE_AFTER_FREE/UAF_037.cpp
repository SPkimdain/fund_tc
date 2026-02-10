#include <string.h>
#include <stdlib.h>

/* UAF_037 - memory function, memcpy, multiple */
void UAF_037_function1(char* dst, char* str, int size) {
  memcpy(dst, str, size);
}

void UAF_037_function2(char* str, int size) {
  char* buf = new char[256];
  if(buf == 0) {
    return;
  }

  UAF_037_function1(buf, str, size);

  char* buf2 = new char[256];
  if(buf2 == 0) {
    delete[] buf;
    return;
  }

  delete[] buf2;

  UAF_037_function1(buf2, str, size); //@violation USE_AFTER_FREE

  delete[] buf;
}
