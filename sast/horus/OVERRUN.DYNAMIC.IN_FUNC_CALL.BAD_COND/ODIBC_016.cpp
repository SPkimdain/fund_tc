#include <string.h>

/* ODIBC_016 - strncpy functions2 */
void ODIBC_016_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

void ODIBC_016_function2(int flag, int size) {
  if(size >= 0 && size < 5) { //[0, 4]
    char src[] = "01234"; //sizeof(src) == 6

    char* dst = new char[5];
    if(dst == 0) {
      return;
    }

    strncpy(dst, src, size + 1); //It's ok. [1, 5]

    size++; //[1, 5]

    //[2, 6]
    strncpy(dst, src, size + 1); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND

    delete[] dst;
  }
}
