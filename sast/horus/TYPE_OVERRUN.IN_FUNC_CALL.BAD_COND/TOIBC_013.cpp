#include <memory.h>

/* TOIBC_013 - memset functions */
class TOIBC_013_Class {
public:
  bool TOIBC_013_function1(char* dst, int size) {
    memset(dst, 0, size);
    return true;
  }

  void TOIBC_013_function2(int flag, int size) {
    if(size < 15) {
      TOIBC_013_function1(dst1, size); //It's ok

      TOIBC_013_function1(dst2, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    }
  }
private:
  char dst1[20];
  char dst2[10];
};

