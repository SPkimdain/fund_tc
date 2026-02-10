#include <memory.h>

/* UDSI_002 - simple memset */
int UDSI_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return -1;
}

int UDSI_002_function2(int offset) {
  char dst[20] = { 0, };

  memset(dst, 50, 20); //It's ok.

  memset(dst + UDSI_002_function1(offset), 20, 10); //@violation UNDERRUN.STATIC.IN_FUNC_CALL

  return 0;
}
