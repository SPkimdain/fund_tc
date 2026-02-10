#include <string.h>

/* OVI_005 - simple strncpy */
void OVI_005_function(int flag) {
  char src[] = "0123456789"; //sizeof(src) == 11
  char dst[5] = { 0, };
  strncpy(dst, src, sizeof(dst) - 1); //It's ok.

  strncpy(dst, src, sizeof(dst) + 1); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
