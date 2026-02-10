#include <stdlib.h>
#include <memory.h>

/* TUDIBC_001 - wrong src index */
struct TUDIBC_001_Class {
  char dst[10];
};

int TUDIBC_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  
  return index;
}

void TUDIBC_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  TUDIBC_001_Class obj;

  if(y > -10) {
    memcpy(obj.dst + TUDIBC_001_function1(y), src, 4); //@violation TYPE_UNDERRUN.IN_FUNC_CALL.BAD_COND
  }
}
