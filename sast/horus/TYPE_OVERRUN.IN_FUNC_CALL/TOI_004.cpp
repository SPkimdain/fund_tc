#include <string.h>

/* TOI_004 - simple strcpy */
struct TOI_004_Class {
  char dst[5];
};

void TOI_004_function() {
  TOI_004_Class obj;
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  strcpy(obj.dst, src2); //It's ok.
  
  strcpy(obj.dst, src); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
