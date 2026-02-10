#include <stdlib.h>
#include <memory.h>

/* OVIBC_021 - src overrun */
void OVIBC_021_function1(int size){
  char src[] = "0123456789"; //sizeof(src) == 11
  char dst[256];

  memset(dst, 0, 256);

  if(size == 4) {
    memcpy(dst, src, 4); //It's ok.
  }
  else if(size < 15) {
    memcpy(dst, src, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}
