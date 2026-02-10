#include <string.h>

/* OVIBC_011 - global variable */
char OVIBC_011_Buf[5] = { 0, };

void OVIBC_011_function(int size) {
  char src[] = "01234678"; //sizeof(src) == 10

  if(size < 10) {
    strncpy(OVIBC_011_Buf, src, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
  
}
