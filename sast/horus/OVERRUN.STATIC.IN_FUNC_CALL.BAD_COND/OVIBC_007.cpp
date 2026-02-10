#include <string.h>

/* OVIBC_007 - simple strncat */
void OVIBC_007_function2(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[6] = { 0, };
  char* ret = 0;
  strcpy(dst, src2); //It's ok.
  
  if(size == 1) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strncat(dst, src, size); //It's ok.
  }
  else {
    if(size < 5) {
      ret = strncat(dst, src, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }
  }
}

