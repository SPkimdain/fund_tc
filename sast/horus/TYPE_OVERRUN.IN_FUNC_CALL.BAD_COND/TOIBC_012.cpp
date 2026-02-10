#include <memory.h>

/* TOIBC_012 - memcpy functions */

class TOIBC_012_Class {
public:
  void TOIBC_012_function1(char* src, int size) {
    memcpy(a, src, size);
  }

  void TOIBC_012_function2(int flag, int size) {
    char str1[] = "01234"; //sizeof(str1) == 6
    char str2[] = "0123456789"; //sizeof(str2) == 11

    if(flag > 0) {
      if(size < 6) {
        TOIBC_012_function1(str1, size); //It's ok.
      }
    }
    else {
      if(size <= 7) {
        TOIBC_012_function1(str2, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
      }
    }
  }

private:
  char a[6];
};

