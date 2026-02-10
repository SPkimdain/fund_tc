#include <string.h>

/* TOI_016 - strncpy functions */
struct TOI_016_Class {
  char dst[5];
};

void TOI_016_function1(TOI_016_Class& obj, char* src, int size) {
  strncpy(obj.dst, src, size);
}

void TOI_016_function2(int flag) {
  char src[] = "01234567"; //sizeof(src) == 6
  TOI_016_Class obj;

  TOI_016_function1(obj, src, sizeof(obj.dst) - 1); //It's ok.

  TOI_016_function1(obj, src, sizeof(src) - 1); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
