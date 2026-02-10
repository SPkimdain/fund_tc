#include <memory.h>

/* ODIBC_002 - simple memset */
int ODIBC_002_function(int index) {
  char* dst = new char[20];
  if(dst == 0) {
    return 0;
  }

  char* dst2 = new char[30];
  if(dst2 == 0) {
    delete[] dst;
    return 0;
  }

  if(index >= 0 && index <= 21) {
    memset(dst2, 50, index); //It's ok.
    
    memset(dst, 20, index); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND

    memset(dst, 20, index); //Ignore.
  }

  delete[] dst;
  delete[] dst2;
  return 0;
}
