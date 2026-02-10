#include <string.h>

/* OVI_016 - strncpy functions */
void OVI_016_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

void OVI_016_function2(int flag) {
  char src[] = "01234567"; //sizeof(src) == 6
  char dst[5] = { 0, };

  OVI_016_function1(dst, src, sizeof(dst) - 1); //It's ok.

  OVI_016_function1(dst, src, sizeof(src) - 1); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
