#include <memory.h>

/* OVI_002 - simple memset */
int OVI_002_function() {
  char dst[20] = { 0, };

  memset(dst, 50, 20); //It's ok.

  memset(dst, 20, 50); //@violation OVERRUN.STATIC.IN_FUNC_CALL

  return 0;
}
