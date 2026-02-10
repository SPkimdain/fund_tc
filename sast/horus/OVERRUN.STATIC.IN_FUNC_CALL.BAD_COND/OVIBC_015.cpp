#include <string.h>

/* OVIBC_015 - strncpy functions1 */
void OVIBC_015_function1(char* dst, char* src, int size) {
  strncpy(dst, src, size);
}

int OVIBC_015_function2(int size) {
  return size + 5;
}

void OVIBC_015_function3(int size) {
  if(size < 5) { //[min, 4]
    char src[] = "0123456789"; //sizeof(src) == 11

    char dst[5] = { 0, };

    OVIBC_015_function1(dst, src, size); //It's ok.

    int index = OVIBC_015_function2(size); //[min, 9]

    OVIBC_015_function1(dst, src, index); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}


