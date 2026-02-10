#include <string.h>

/* OVIBC_017 - strcat functions */
char* OVIBC_017_function1(char* dst, char* src) {
  return strcat(dst, src);
}

void OVIBC_017_function(int flag, int size, char* src) {
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

    strcpy(dst, src2); //It's ok. , last offset is 4.

    if(flag > 0) {
      ret = OVIBC_017_function1(dst, src3); //It's ok
    }
    else {
      ret = OVIBC_017_function1(dst, temp); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    }

    delete[] temp;
  }
}
