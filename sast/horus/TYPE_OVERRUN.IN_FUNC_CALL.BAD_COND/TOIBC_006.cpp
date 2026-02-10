#include <string.h>

/* TOIBC_006 - simple strcat */
struct TOIBC_006_Class {
  char dst[6];
};


void TOIBC_006_function(int flag, int size, char* src) {
  if(size < 6) {
    char* temp = new char[size];
    if(temp == 0) {
      return;
    }
    strcpy(temp, src);

    char src2[] = "fghi"; //sizeof(src2) == 5
    char src3[] = "1"; //sizeof(src3) == 2
    char* ret = 0;
    TOIBC_006_Class obj;

    strcpy(obj.dst, src2); //It's ok.

    if(flag > 0) {
      ret = strcat(obj.dst, src3); //It's ok
    }
    else {
      ret = strcat(obj.dst, temp); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    }

    delete[] temp;
  }
}
