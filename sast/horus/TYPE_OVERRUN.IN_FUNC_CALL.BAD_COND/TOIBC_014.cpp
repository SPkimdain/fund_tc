#include <string.h>

/* TOIBC_014 - memmove functions */
struct TOIBC_014_Class {
  char str[11];
};

void TOIBC_014_function1(int size) {
  TOIBC_014_Class obj;
  strcpy(obj.str, "0123456789");
  memmove(obj.str + 3, obj.str + 7, size);
}

void TOIBC_014_function2(int size) {
  if(size <= 5) {
    TOIBC_014_function1(size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}

