#include <string.h>

/* TOI_007 - simple strncat */
struct TOI_007_Class {
  char dst[6];
};

void TOI_007_function2(int flag) {
  TOI_007_Class obj;
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char* ret = 0;
  strcpy(obj.dst, src2); //It's ok.
  
  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strncat(obj.dst, src, 1); //It's ok.
  }
  else {
    //memory : 4 + 4 + 1, dst size is 6
    ret = strncat(obj.dst, src, 4); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}

