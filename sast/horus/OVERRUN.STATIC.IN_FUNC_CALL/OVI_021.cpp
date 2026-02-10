#include <stdlib.h>
#include <memory.h>

/* OVI_021 - src overrun */
void OVI_021_function1(){
  char src[] = "0123456789"; //sizeof(src) == 11
  char dst[256];

  memset(dst, 0, 256);

  memcpy(dst, src, 4); //It's ok.

  memcpy(dst, src, 15); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
