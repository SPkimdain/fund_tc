#include <string.h>

/* ODIBC_004 - simple strcpy */
void ODIBC_004_function(int size, char* src) {
  if(size < 10) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }

    char* dst = new char[5];
    if(dst == 0) {
      delete[] temp;
      return;
    }
    strcpy(temp, src); //It's ok.

    strcpy(dst, temp); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND

    delete[] temp;
    delete[] dst;
  }
}
