#include <stdlib.h>
#include <memory.h>

/* TUDI_001 - wrong src index */
struct TUDI_001_Class {
  char dst[10];
};

int TUDI_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  return -1;
}

void TUDI_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  TUDI_001_Class obj;

  memcpy(obj.dst + TUDI_001_function1(y), src, 4); //@violation TYPE_UNDERRUN.IN_FUNC_CALL
}
