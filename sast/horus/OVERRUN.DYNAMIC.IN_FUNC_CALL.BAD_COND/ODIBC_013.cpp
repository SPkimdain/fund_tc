#include <memory.h>

/* ODIBC_013 - memset functions */
bool ODIBC_013_function1(char* dst, int size) {
  memset(dst, 0, size);
  return true;
}

void ODIBC_013_function2(int flag, int size) {
  char* dst1 = new char[20];
  if(dst1 == 0) {
    return;
  }

  char* dst2 = new char[10];
  if(dst2 == 0) {
    delete[] dst1;
    return;
  }

  if(size < 15) {
    ODIBC_013_function1(dst1, size); //It's ok

    ODIBC_013_function1(dst2, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }

  delete[] dst1;
  delete[] dst2;
}

