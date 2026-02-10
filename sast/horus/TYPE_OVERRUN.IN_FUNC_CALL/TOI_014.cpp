#include <string.h>

/* TOI_014 - memmove functions */
struct TOI_014_Class {
  char str[11];
};

void TOI_014_function1(int offset1, int offset2, int size) {
  TOI_014_Class obj;
  strcpy(obj.str, "0123456789");
  memmove(obj.str + offset1, obj.str + offset2, size);
}

void TOI_014_function2() {
  TOI_014_function1(5, 2, 5); //It's ok.

  TOI_014_function1(3, 7, 5); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}

