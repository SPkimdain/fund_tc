#include <string.h>
#include <stdlib.h>

/* UAF_038 - memory function, memset, multiple */
void UAF_038_function1(char* dst, int size) {
  memset(dst, 0, size);
}

void UAF_038_function2(int size) {
  char* buf = new char[size];
  if(buf == 0) {
    return;
  }

  UAF_038_function1(buf, size);

  char* buf2 = new char[size];
  if(buf2 == 0) {
    delete[] buf;
    return;
  }

  delete[] buf2;

  UAF_038_function1(buf2, size); //@violation USE_AFTER_FREE

  delete[] buf;
}
