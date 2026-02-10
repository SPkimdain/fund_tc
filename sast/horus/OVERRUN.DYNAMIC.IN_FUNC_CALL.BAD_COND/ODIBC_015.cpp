#include <string.h>

/* ODIBC_015 - strncpy functions1 */
void ODIBC_015_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

int ODIBC_015_function2(int size) {
  return size + 5;
}

void ODIBC_015_function3(int size) {
  if(size < 5) { //[min, 4]
    char src[] = "0123456789"; //sizeof(src) == 11

    char* dst = new char[5];
    if(dst == 0) {
      return;
    }

    ODIBC_015_function1(dst, src, size); //It's ok.

    int index = ODIBC_015_function2(size); //[min, 9]

    ODIBC_015_function1(dst, src, index); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND

    delete[] dst;
  }
}


