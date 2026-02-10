#include <memory.h>

/* ODIBC_012 - memcpy functions */
void ODIBC_012_function1(char* src, int size) {
  char* a = new char[6];
  if(a == 0) {
    return;
  }

  memcpy(a, src, size);
  delete[] a;
}

void ODIBC_012_function2(int flag, int size) {
  char str1[] = "01234"; //sizeof(str1) == 6
  char str2[] = "0123456789"; //sizeof(str2) == 11

  if(flag > 0) {
    if(size < 6) {
      ODIBC_012_function1(str1, size); //It's ok.
    }
  }
  else {
    if(size <= 7) {
      ODIBC_012_function1(str2, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    }
  }
}
