#include <memory.h>

/* OVIBC_012 - memcpy functions */
void OVIBC_012_function1(char* src, int size) {
  char a[6];
  memcpy(a, src, size); 
}

void OVIBC_012_function2(int flag, int size) {
  char str1[] = "01234"; //sizeof(str1) == 6
  char str2[] = "0123456789"; //sizeof(str2) == 11

  if(flag > 0) {
    if(size < 6) {
      OVIBC_012_function1(str1, size); //It's ok.
    }
  }
  else {
    if(size <= 7) {
      OVIBC_012_function1(str2, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }
  }
}
