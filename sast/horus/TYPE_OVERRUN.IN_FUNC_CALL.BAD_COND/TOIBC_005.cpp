#include <string.h>

/* TOIBC_005 - simple strncpy */
struct TOIBC_005_Class {
  char dst[5];
};

void TOIBC_005_function(int flag, int size) {
  char src[] = "0123456789"; //sizeof(src) == 11
  TOIBC_005_Class obj;
  if(size < 7) {
    strncpy(obj.dst, src, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}
