#include <string.h>

/* TOIBC_007 - simple strncat */
struct TOIBC_007_Class {
  char dst[6];
};

void TOIBC_007_function2(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  TOIBC_007_Class obj;

  char* ret = 0;
  strcpy(obj.dst, src2); //It's ok.
  
  if(size == 1) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strncat(obj.dst, src, size); //It's ok.
  }
  else {
    if(size < 5) {
      ret = strncat(obj.dst, src, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    }
  }
}

