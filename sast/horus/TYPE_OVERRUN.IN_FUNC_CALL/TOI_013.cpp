#include <memory.h>

/* TOI_013 - memset functions */
struct TOI_013_Class {
  char dst1[20];
  char dst2[10];
};

bool TOI_013_function1(char* dst, int size) {
  memset(dst, 0, size);
  return true;
}

void TOI_013_function2(int flag) {
  TOI_013_Class obj;

  TOI_013_function1(obj.dst1, sizeof(obj.dst1)); //It's ok

  TOI_013_function1(obj.dst2, sizeof(obj.dst1)); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
