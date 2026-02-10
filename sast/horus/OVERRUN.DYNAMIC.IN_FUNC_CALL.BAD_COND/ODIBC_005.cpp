#include <string.h>

/* ODIBC_005 - simple strncpy */
void ODIBC_005_function(int flag, int size) {
  char src[] = "0123456789"; //sizeof(src) == 11
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  if(size < 7) {
    strncpy(dst, src, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }

  delete[] dst;
}
