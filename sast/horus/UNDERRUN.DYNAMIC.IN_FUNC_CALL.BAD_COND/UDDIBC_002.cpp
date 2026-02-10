#include <memory.h>

/* UDDIBC_002 - simple memset */
int UDDIBC_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return offset;
}

int UDDIBC_002_function2(int offset) {
  char* dst = new char[20];
  if(dst == 0) {
    return 0;
  }

  memset(dst, 50, 20); //It's ok.

  if(offset >= -10) {
    memset(dst + UDDIBC_002_function1(offset), 20, 5); //@violation UNDERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }

  delete[] dst;

  return 0;
}
