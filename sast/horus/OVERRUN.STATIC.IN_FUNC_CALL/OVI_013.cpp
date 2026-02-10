#include <memory.h>

/* OVI_013 - memset functions */
bool OVI_013_function1(char* dst, int size) {
  memset(dst, 0, size);
  return true;
}

void OVI_013_function2(int flag) {
  char dst1[20];
  char dst2[10];

  OVI_013_function1(dst1, sizeof(dst1)); //It's ok

  OVI_013_function1(dst2, sizeof(dst1)); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
