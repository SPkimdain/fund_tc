#include <string.h>

/* ODIBC_019 - multiple strcat */
void ODIBC_019_function(int flag, int size, char* str) {
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4

  if(size < 6) {
    char* src3 = new char[size];
    if(src3 == 0) {
      return;
    }
    strcpy(src3, str);

    char* dst = new char[20];
    if(dst == 0) {
      delete[] src3;
      return;
    }
    char* ret = 0;
    strcpy(dst, src2); //It's ok. len = 4 + 1

    strcat(dst, src2); //It's ok. len = 4 + 4 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 1
    strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 5 + 1

    //len = 4 + 4 + 5 + 5 + 5 + 1 = 24
    strcat(dst, src3); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    
    delete[] src3;
    delete[] dst;
  }
}

