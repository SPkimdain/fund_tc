#include <memory.h>

/* OVI_012 - memcpy functions */
void OVI_012_function1(char* src, int size) {
  char a[6];
  memcpy(a, src, size); 
}

void OVI_012_function2(int flag) {
  char str1[] = "01234"; //sizeof(str1) == 6
  char str2[] = "0123456789"; //sizeof(str2) == 11

  if(flag > 0) {
    OVI_012_function1(str1, sizeof(str1)); //It's ok.
  }
  else {
    OVI_012_function1(str2, sizeof(str2)); //@violation OVERRUN.STATIC.IN_FUNC_CALL
  }
}
