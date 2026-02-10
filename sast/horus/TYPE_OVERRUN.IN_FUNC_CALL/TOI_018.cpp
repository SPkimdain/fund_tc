#include <string.h>

/* TOI_018 - strncat functions */
struct TOI_018_Class {
  char dst[6];
};

char* TOI_018_function1(char* dst, char* src, int size) {
  return strncat(dst, src, size);
}

void TOI_018_function2(int flag) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  TOI_018_Class obj;
  char* ret = 0;
  strcpy(obj.dst, src2); //It's ok.

  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = TOI_018_function1(obj.dst, src, 1); //It's ok.
  }
  else {
    //memory : 4 + 4 + 1, dst size is 6
    ret = TOI_018_function1(obj.dst, src, 4); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}

