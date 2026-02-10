#include <string.h>

/* ODI_017 - strcat functions */
char* ODI_017_function1(char* dst, char* src) {
  return strcat(dst, src);
}

void ODI_017_function(int flag) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char src3[] = "1"; //sizeof(src3) == 2
  char* ret = 0;
  char* dst = new char[6];
  if(dst == 0) {
    return;
  }

  strcpy(dst, src2); //It's ok. , last offset is 4.

  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = ODI_017_function1(dst, src3); //It's ok
  }
  else {
    //memory : 4 + 5 + 1, dst size is 6
    ret = ODI_017_function1(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  }

  delete[] dst;
}
