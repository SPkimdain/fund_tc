#include <string.h>

/* ODI_014 - memmove functions */
void ODI_014_function1(int offset1, int offset2, int size) {
  char str[] = "0123456789"; //sizeof(src) == 11
  char* dst = new char[sizeof(str)];
  if(dst == 0) {
    return;
  }
  memcpy(dst, str, sizeof(str));

  memmove(dst + offset1, dst + offset2, size);

  delete[] dst;
}

void ODI_014_function2() {
  ODI_014_function1(5, 2, 5); //It's ok.

  ODI_014_function1(3, 7, 5); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
}

