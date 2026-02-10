#include <memory.h>

/* OVIBC_002 - simple memset */
int OVIBC_002_function(int index) {
  char dst[20] = { 0, };
  char dst2[30] = { 0, };

  if(index >= 0 && index <= 21) {
    memset(dst2, 50, index); //It's ok.
    
    memset(dst, 20, index); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND

    memset(dst, 20, index); //Ignore.
  }

  return 0;
}
