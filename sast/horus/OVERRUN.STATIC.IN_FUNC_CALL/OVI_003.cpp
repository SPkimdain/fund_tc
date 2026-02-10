#include <string.h>

/* OVI_003 - simple memmove */
void OVI_003_function(int flag) {
  char str[] = "0123456789"; //sizeof(src) == 11
  if(flag == 1) {
    memmove(str + 5, str + 2, 5); //It's ok.
  }
  else {
    memmove(str + 7, str + 2, 5); //@violation OVERRUN.STATIC.IN_FUNC_CALL
  }
}
