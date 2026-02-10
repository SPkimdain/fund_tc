#include <memory.h>

/* UDDI_002 - simple memset */
int UDDI_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return -1;
}

int UDDI_002_function2(int offset) {
  char* dst = new char[20];
  if(dst == 0) {
    return 0;
  }

  memset(dst, 50, 20); //It's ok.

  memset(dst + UDDI_002_function1(offset), 20, 10); //@violation UNDERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;

  return 0;
}
