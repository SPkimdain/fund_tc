#include <string.h>

/* ODIBC_014 - memmove functions */
void ODIBC_014_function1(int size) {
  char str[] = "0123456789"; //sizeof(src) == 11
  char* dst = new char[sizeof(str)];
  if(dst == 0) {
    return;
  }
  memcpy(dst, str, sizeof(str));

  memmove(dst + 3, dst + 7, size);

  delete[] dst;
}

void ODIBC_014_function2(int size) {
  if(size <= 5) {
    ODIBC_014_function1(size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }
}

