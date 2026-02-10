#include <stdlib.h>
#include <memory.h>

/* UDDI_001 - wrong src index */
int UDDI_001_function1(int index) {
  if(index > 0) {
    return ++index;
  }
  return -1;
}

void UDDI_001_function2(unsigned int x, int y){
  char* src = "asd"; //sizeof(src) == 4
  char* dst = new char[10];
  if(dst == 0) {
    return;
  }

  memcpy(dst + UDDI_001_function1(y), src, 4); //@violation UNDERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;
}
