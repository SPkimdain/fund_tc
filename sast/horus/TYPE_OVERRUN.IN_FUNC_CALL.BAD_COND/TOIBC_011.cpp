#include <string.h>

/* TOIBC_011 - global variable */
struct TOIBC_011_Class {
  char dst[5];
};

TOIBC_011_Class toi011Array;

void TOIBC_011_function(int size) {
  char src[] = "01234678"; //sizeof(src) == 10

  if(size < 10) {
    strncpy(toi011Array.dst, src, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
  
}
