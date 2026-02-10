#include <string.h>

/* OVI_015 - strcpy functions */
void OVI_015_function1(char* dst, char* src) {
  strcpy(dst, src);
}

void OVI_015_function2() {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[5] = { 0, };

  OVI_015_function1(dst, src2); //It's ok.

  OVI_015_function1(dst, src); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}


