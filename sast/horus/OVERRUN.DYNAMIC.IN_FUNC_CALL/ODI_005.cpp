#include <string.h>

/* ODI_005 - simple strncpy */
void ODI_005_function(int flag) {
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  char src[] = "0123456789"; //sizeof(src) == 11

  strncpy(dst, src, 4); //It's ok.

  strncpy(dst, src, 6); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;
}
