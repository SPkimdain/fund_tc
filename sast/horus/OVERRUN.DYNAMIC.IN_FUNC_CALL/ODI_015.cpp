#include <string.h>

/* ODI_015 - strcpy functions */
void ODI_015_function1(char* dst, char* src) {
  strcpy(dst, src);
}

void ODI_015_function2() {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  ODI_015_function1(dst, src2); //It's ok.

  ODI_015_function1(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;
}


