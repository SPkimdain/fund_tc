#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* ODI_022 - complex strncpy */
int ODI_022_function1(char* str){
  return strlen(str);
}

void ODI_022_function2(char* dst, char* src, int size){
  strncpy(dst, src, size);
}

void ODI_022_function3(char* src, int size){
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  ODI_022_function2(dst, src, size);

  delete[] dst;
}

void ODI_022_function4(int flag){
  char src[] = "012345"; //sizeof(src) == 7, len == 6
  char src2[] = "012"; //sizeof(src) == 4, len == 3

  int len = ODI_022_function1(src);
  int len2 = ODI_022_function1(src2);
  if(flag > 0) {
    ODI_022_function3(src, len); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  }
  else {
    ODI_022_function3(src2, len2); //It's ok.
  }
}


