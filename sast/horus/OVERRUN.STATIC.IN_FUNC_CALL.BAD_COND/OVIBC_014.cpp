#include <string.h>

/* OVIBC_014 - memmove functions */
void OVIBC_014_function1(int size) {
  char str[] = "0123456789"; //sizeof(src) == 11
  memmove(str + 3, str + 7, size);
}

void OVIBC_014_function2(int size) {
  if(size <= 5) {
    OVIBC_014_function1(size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}

