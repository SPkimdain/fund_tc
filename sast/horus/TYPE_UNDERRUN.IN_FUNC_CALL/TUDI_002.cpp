#include <memory.h>

/* TUDI_002 - simple memset */
struct TUDI_002_Struct {
  char dst[20];
};

int TUDI_002_function1(int offset) {
  if(offset > 0) {
    return ++offset;
  }
  
  return -1;
}

int TUDI_002_function2(int offset) {
  TUDI_002_Struct obj;

  memset(obj.dst, 50, 20); //It's ok.

  memset(obj.dst + TUDI_002_function1(offset), 20, 10); //@violation TYPE_UNDERRUN.IN_FUNC_CALL

  return 0;
}
