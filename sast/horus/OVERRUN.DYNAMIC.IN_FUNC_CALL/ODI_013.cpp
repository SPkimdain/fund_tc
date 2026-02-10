#include <memory.h>

/* ODI_013 - memset functions */
bool ODI_013_function1(char* dst, int size) {
  memset(dst, 0, size);
  return true;
}

void ODI_013_function2(int flag) {
  char* dst1 = new char[20];
  if(dst1 == 0) {
    return;
  }

  char* dst2 = new char[10];
  if(dst2 == 0) {
    delete[] dst1;
    return;
  }

  ODI_013_function1(dst1, 20); //It's ok

  ODI_013_function1(dst2, 20); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst1;
  delete[] dst2;
}
