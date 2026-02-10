#include <string.h>

/* TOI_011 - global variable */
struct TOI_011_Class {
  char dst[5];
};
TOI_011_Class obj;

void TOI_011_function() {
  char src[] = "abcde"; // sizeof(src) == 6
  strcpy(obj.dst, src); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
