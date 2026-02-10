#include <string.h>

/* OVIBC_018 - strncat functions */
char* OVIBC_018_function1(char* dst, char* src, int size) {
  return strncat(dst, src, size);
}

void OVIBC_018_function2(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[6] = { 0, };
  char* ret = 0;
  strcpy(dst, src2); //It's ok.

  if(size == 1) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = OVIBC_018_function1(dst, src, size); //It's ok.
  }
  else {
    if(size < 5) {
      ret = OVIBC_018_function1(dst, src, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }
  }
}

