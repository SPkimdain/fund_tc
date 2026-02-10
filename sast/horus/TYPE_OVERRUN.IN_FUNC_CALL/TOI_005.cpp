#include <string.h>

/* TOI_005 - simple strncpy */
struct TOI_005_Class {
  char dst[5];
};

void TOI_005_function(int flag) {
  TOI_005_Class obj;
  char src[] = "0123456789"; //sizeof(src) == 11
  strncpy(obj.dst, src, sizeof(obj.dst) - 1); //It's ok.

  strncpy(obj.dst, src, sizeof(obj.dst) + 1); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
