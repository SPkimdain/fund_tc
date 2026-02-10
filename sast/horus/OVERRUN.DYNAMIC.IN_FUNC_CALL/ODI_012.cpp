#include <memory.h>

/* ODI_012 - memcpy functions */
void ODI_012_function1(char* src, int size) {
  char* a = new char[6];
  if(a == 0) {
    return;
  }

  memcpy(a, src, size); 
  delete[] a;
}

void ODI_012_function2(int flag) {
  char str1[] = "01234"; //sizeof(str1) == 6
  char str2[] = "0123456789"; //sizeof(str2) == 11

  if(flag > 0) {
    ODI_012_function1(str1, sizeof(str1)); //It's ok.
  }
  else {
    ODI_012_function1(str2, sizeof(str2)); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  }
}
