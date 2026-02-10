#include <string.h>

/* OVIBC_003 - simple memmove */
void OVIBC_003_function(int flag, int index) {
  char str[] = "0123456789"; //sizeof(src) == 11
  if(flag == 1) {
    if(index < 6) {
      memmove(str + index, str + 2, 5); //It's ok.
    }
  }
  else {
    if(index < 10) {
      memmove(str + index, str + 2, 5); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }
  }
}
