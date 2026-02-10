#include <string.h>

/* ODIBC_006 - simple strcat */
void ODIBC_006_function(int flag, int size, char* src) {
  if(size < 6) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }
    strcpy(temp, src);

    char src2[] = "fghi"; //sizeof(src2) == 5
    char src3[] = "1"; //sizeof(src3) == 2
    char* dst = new char[6];
    if(dst == 0) {
      delete[] temp;
      return;
    }

    char* ret = 0;

    strcpy(dst, src2); //It's ok.

    if(flag > 0) {
      ret = strcat(dst, src3); //It's ok
    }
    else {
      ret = strcat(dst, temp); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    }

    delete[] temp;
    delete[] dst;
  }
}
