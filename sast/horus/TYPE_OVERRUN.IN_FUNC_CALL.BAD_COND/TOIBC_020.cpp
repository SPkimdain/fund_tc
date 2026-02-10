#include <string.h>

/* TOIBC_020 - multiple strncat */
struct TOIBC_020_Class {
  char dst[20];
};

void TOIBC_020_function(int flag, int offset) {
  float value = 10.5F;
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4
  TOIBC_020_Class obj;
  char* ret = 0;
  strcpy(obj.dst, src2); //It's ok. len = 4 + 1

  strncat(obj.dst, src2, 3); //It's ok. len = 4 + 3 + 1
  strncat(obj.dst, src, 4); //It's ok. len = 4 + 3 + 4 + 1
  strncat(obj.dst, src, 5); //It's ok. len = 4 + 3 + 4 + 5 + 1

  if(offset < 6) {
    //len = 4 + 3 + 4 + 5 + 5 + 1 = 22
    strncat(obj.dst, src, offset); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}


