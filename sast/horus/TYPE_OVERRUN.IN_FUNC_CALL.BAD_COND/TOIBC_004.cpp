#include <string.h>

/* TOIBC_004 - simple strcpy */
struct TOIBC_004_Class {
  char dst[5];
};


void TOIBC_004_function(int size, char* src) {
  if(size < 10) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }
    TOIBC_004_Class obj;
    strcpy(temp, src); //It's ok.

    strcpy(obj.dst, temp); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND

    delete[] temp;
  }
}
