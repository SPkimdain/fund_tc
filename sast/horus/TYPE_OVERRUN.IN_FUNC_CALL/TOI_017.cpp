#include <string.h>

/* TOI_017 - strcat functions */
struct TOI_017_Class {
  char dst[6];
};

char* TOI_017_function1(char* dst, char* src) {
  return strcat(dst, src);
}

void TOI_017_function(int flag) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char src3[] = "1"; //sizeof(src3) == 2
  TOI_017_Class obj;
  char* ret = 0;

  strcpy(obj.dst, src2); //It's ok. , last offset is 4.

  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = TOI_017_function1(obj.dst, src3); //It's ok
  }
  else {
    //memory : 4 + 5 + 1, dst size is 6
    ret = TOI_017_function1(obj.dst, src); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}
