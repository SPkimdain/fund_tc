#include <string.h>

/* OVI_018 - strncat functions */
char* OVI_018_function1(char* dst, char* src, int size) {
  return strncat(dst, src, size);
}

void OVI_018_function2(int flag) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[6] = { 0, };
  char* ret = 0;
  strcpy(dst, src2); //It's ok.

  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = OVI_018_function1(dst, src, 1); //It's ok.
  }
  else {
    //memory : 4 + 4 + 1, dst size is 6
    ret = OVI_018_function1(dst, src, 4); //@violation OVERRUN.STATIC.IN_FUNC_CALL
  }
}

