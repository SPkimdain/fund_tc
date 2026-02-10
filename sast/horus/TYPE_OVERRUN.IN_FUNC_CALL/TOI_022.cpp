#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* TOI_022 - complex strncpy */
struct TOI_022_Class {
  char dst[5];
};

int TOI_022_function1(char* str){
  return strlen(str);
}

void TOI_022_function2(TOI_022_Class& obj, char* src, int size){
  strncpy(obj.dst, src, size);
}

void TOI_022_function3(char* src, int size){
  TOI_022_Class obj;
  TOI_022_function2(obj, src, size);
}

void TOI_022_function4(int flag){
  char src[] = "012345"; //sizeof(src) == 7, len == 6
  char src2[] = "012"; //sizeof(src) == 4, len == 3

  int len = TOI_022_function1(src);
  int len2 = TOI_022_function1(src2);
  if(flag > 0) {
    TOI_022_function3(src, len); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
  else {
    TOI_022_function3(src2, len2); //It's ok.
  }
}


