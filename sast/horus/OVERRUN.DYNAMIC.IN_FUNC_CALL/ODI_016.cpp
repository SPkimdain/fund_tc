#include <string.h>

/* ODI_016 - strncpy functions */
void ODI_016_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

void ODI_016_function2(int flag) {
  char src[] = "01234567"; //sizeof(src) == 6
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  ODI_016_function1(dst, src, sizeof(dst) - 1); //It's ok.

  ODI_016_function1(dst, src, sizeof(src) - 1); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  
  delete[] dst;
}
