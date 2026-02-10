#include <string.h>

/* OVIBC_004 - simple strcpy */
void OVIBC_004_function(int size, char* src) {
  if(size < 10) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }
    char dst[5] = { 0, };
    strcpy(temp, src); //It's ok.

    strcpy(dst, temp); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND

    delete[] temp;
  }
}
