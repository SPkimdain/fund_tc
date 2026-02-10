#include <string.h>

/* TOIBC_019 - multiple strcat */
struct TOIBC_019_Class {
  char dst[20];
};

void TOIBC_019_function(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4

  if(size < 6) {
    char* src3 = new char[size];
    TOIBC_019_Class obj;
    char* ret = 0;
    strcpy(obj.dst, src2); //It's ok. len = 4 + 1

    strcat(obj.dst, src2); //It's ok. len = 4 + 4 + 1
    strcat(obj.dst, src); //It's ok. len = 4 + 4 + 5 + 1
    strcat(obj.dst, src); //It's ok. len = 4 + 4 + 5 + 5 + 1

    //len = 4 + 4 + 5 + 5 + 5 + 1 = 24
    strcat(obj.dst, src3); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    delete[] src3;
  }
}

