#include <string.h>

/* TOIBC_016 - strncpy functions2 */
struct TOIBC_016_Class {
  char dst[5];
};


void TOIBC_016_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

void TOIBC_016_function2(int flag, int size) {
  if(size >= 0 && size < 5) { //[0, 4]
    char src[] = "01234"; //sizeof(src) == 6
    TOIBC_016_Class obj;

    strncpy(obj.dst, src, size + 1); //It's ok. [1, 5]

    size++; //[1, 5]

    //[2, 6]
    strncpy(obj.dst, src, size + 1); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}
