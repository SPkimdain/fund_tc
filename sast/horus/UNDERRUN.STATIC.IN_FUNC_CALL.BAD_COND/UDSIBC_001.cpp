#include <stdlib.h>
#include <memory.h>

/* UDSIBC_001 - wrong src index */
int UDSIBC_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  
  return index;
}

void UDSIBC_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  char dst[10];

  if(y > -10) {
    memcpy(dst, src + UDSIBC_001_function1(y), 4); //@violation UNDERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}
