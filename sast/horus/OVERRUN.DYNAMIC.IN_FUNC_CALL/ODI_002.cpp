#include <memory.h>

/* ODI_002 - simple memset */
int ODI_002_function() {
  char* dst = new char[20];
  if(dst == 0) {
    return 0;
  }

  memset(dst, 50, 20); //It's ok.

  memset(dst, 20, 50); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  
  delete[] dst;
  return 0;
}
