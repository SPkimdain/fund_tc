#include <stdlib.h>
#include <memory.h>

/* UDSI_001 - wrong src index */
int UDSI_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  return -1;
}

void UDSI_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  char dst[10];

  memcpy(dst, src + UDSI_001_function1(y), 4); //@violation UNDERRUN.STATIC.IN_FUNC_CALL
}
