#include <string.h>

/* OVIBC_019 - multiple strcat */
void OVIBC_019_function(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4

  if(size < 6) {
    char* src3 = new char[size];

    char dst[20] = { 0, };
    char* ret = 0;
    strcpy(dst, src2); //It's ok. len = 4 + 1

    strcat(dst, src2); //It's ok. len = 4 + 4 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 5 + 1

    //len = 4 + 4 + 5 + 5 + 5 + 1 = 24
    strcat(dst, src3); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    delete[] src3;
  }
}

