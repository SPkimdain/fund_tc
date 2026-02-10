#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* OVIBC_023 - complext strncat */
void OVIBC_023_function1() {
  char actualOption[20] = { 0, };
  
  strncat(actualOption, "b", 2); //It's ok.
}

void OVIBC_023_function2(int flag, int size){
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
