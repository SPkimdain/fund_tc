#include <string.h>

/* OVI_014 - memmove functions */
void OVI_014_function1(int offset1, int offset2, int size) {
  char str[] = "0123456789"; //sizeof(src) == 11
  memmove(str + offset1, str + offset2, size);
}

void OVI_014_function2() {
  OVI_014_function1(5, 2, 5); //It's ok.

  OVI_014_function1(3, 7, 5); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}

