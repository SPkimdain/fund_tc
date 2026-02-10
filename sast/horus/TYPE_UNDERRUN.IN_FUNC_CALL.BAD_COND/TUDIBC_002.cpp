#include <memory.h>

/* TUDIBC_002 - simple memset */
struct TUDIBC_002_Class {
  char dst[20];
};

int TUDIBC_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return offset;
}

int TUDIBC_002_function2(int offset) {
  TUDIBC_002_Class obj;

  memset(obj.dst, 50, 20); //It's ok.

  if(offset >= -10) {
    memset(obj.dst + TUDIBC_002_function1(offset), 20, 5); //@violation TYPE_UNDERRUN.IN_FUNC_CALL.BAD_COND
  }

  return 0;
}
