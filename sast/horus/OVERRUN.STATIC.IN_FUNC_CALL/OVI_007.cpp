#include <string.h>

/* OVI_007 - simple strncat */
void OVI_007_function2(int flag) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char dst[6] = { 0, };
  char* ret = 0;
  strcpy(dst, src2); //It's ok.
  
  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strncat(dst, src, 1); //It's ok.
  }
  else {
    //memory : 4 + 4 + 1, dst size is 6
   ret = strncat(dst, src, 4); //@violation OVERRUN.STATIC.IN_FUNC_CALL
  }
}

