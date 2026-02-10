#include <stdlib.h>
#include <memory.h>

/* UDDIBC_001 - wrong src index */
int UDDIBC_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  
  return index;
}

void UDDIBC_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  char* dst = new char[10];
  if(dst == 0) {
    return;
  }

  if(y > -10) {
    memcpy(dst + UDDIBC_001_function1(y), src, 4); //@violation UNDERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }

  delete[] dst;
}
