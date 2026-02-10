#include <memory.h>

/* UDSIBC_002 - simple memset */
int UDSIBC_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return offset;
}

int UDSIBC_002_function2(int offset) {
  char dst[20] = { 0, };

  memset(dst, 50, 20); //It's ok.

  if(offset >= -10) {
    memset(dst + UDSIBC_002_function1(offset), 20, 5); //@violation UNDERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }

  return 0;
}
