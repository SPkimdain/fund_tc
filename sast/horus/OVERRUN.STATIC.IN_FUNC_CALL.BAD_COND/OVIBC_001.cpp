#include <stdlib.h>
#include <memory.h>

/* OVIBC_001 - simple memcpy */
void OVIBC_001_function1(int flag, int size){
  char* src = "asd"; //sizeof(src) == 4
  char* src2 = "abcd"; //sizeof(src2) == 5
  char dst[4] = { 0, };

  if(size >= 0) {
    if(flag > 0) {
      memcpy(dst, src, size); //Ignore.
    }
    else {
      if(size < 6) {
        memcpy(dst, src2, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
      }
    }
  }

  
}
