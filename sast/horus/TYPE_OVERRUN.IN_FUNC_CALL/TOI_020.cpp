#include <string.h>

/* TOI_020 - multiple strncat */
struct TOI_020_Class {
  char dst[20];
};

void TOI_020_function(int flag) {
  float value = 10.5F;
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4
  TOI_020_Class obj;
  char* ret = 0;
  strcpy(obj.dst, src2); //It's ok. len = 4 + 1

  strncat(obj.dst, src2, 3); //It's ok. len = 4 + 3 + 1
  strncat(obj.dst, src, 4); //It's ok. len = 4 + 3 + 4 + 1
  strncat(obj.dst, src, 5); //It's ok. len = 4 + 3 + 4 + 5 + 1

  //len = 4 + 3 + 4 + 5 + 5 + 1 = 22
  strncat(obj.dst, src, 5); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}


