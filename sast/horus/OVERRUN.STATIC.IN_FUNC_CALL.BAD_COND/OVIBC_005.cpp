#include <string.h>

/* OVIBC_005 - simple strncpy */
void OVIBC_005_function(int flag, int size) {
  char src[] = "0123456789"; //sizeof(src) == 11
  char dst[5] = { 0, };
  if(size < 7) {
    strncpy(dst, src, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}
