#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* OVI_022 - complex strncpy */
int OVI_022_function1(char* str){
  return strlen(str);
}

void OVI_022_function2(char* dst, char* src, int size){
  strncpy(dst, src, size);
}

void OVI_022_function3(char* src, int size){
  char dst[5];
  OVI_022_function2(dst, src, size);
}

void OVI_022_function4(int flag){
  char src[] = "012345"; //sizeof(src) == 7, len == 6
  char src2[] = "012"; //sizeof(src) == 4, len == 3

  int len = OVI_022_function1(src);
  int len2 = OVI_022_function1(src2);
  if(flag > 0) {
    OVI_022_function3(src, len); //@violation OVERRUN.STATIC.IN_FUNC_CALL
  }
  else {
    OVI_022_function3(src2, len2); //It's ok.
  }
}


