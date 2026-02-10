#include <string.h>

/* OVIBC_006 - simple strcat */
void OVIBC_006_function(int flag, int size, char* src) {
  if(size < 6) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }
    strcpy(temp, src);

    char src2[] = "fghi"; //sizeof(src2) == 5
    char src3[] = "1"; //sizeof(src3) == 2
    char dst[6] = { 0, };
    char* ret = 0;

    strcpy(dst, src2); //It's ok.

    if(flag > 0) {
      ret = strcat(dst, src3); //It's ok
    }
    else {
      ret = strcat(dst, temp); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }

    delete[] temp;
  }
}
