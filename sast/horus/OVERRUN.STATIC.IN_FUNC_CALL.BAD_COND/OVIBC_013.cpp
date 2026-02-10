#include <memory.h>

/* OVIBC_013 - memset functions */
bool OVIBC_013_function1(char* dst, int size) {
  memset(dst, 0, size);
  return true;
}

void OVIBC_013_function2(int flag, int size) {
  char dst1[20];
  char dst2[10];

  if(size < 15) {
    OVIBC_013_function1(dst1, size); //It's ok

    OVIBC_013_function1(dst2, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}
