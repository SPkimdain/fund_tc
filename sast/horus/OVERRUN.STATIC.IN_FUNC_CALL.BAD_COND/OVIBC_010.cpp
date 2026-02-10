#include <string.h>

/* OVIBC_010 - boundary check */
void OVIBC_010_function1(char* src, int size) {
  char dst[10];
  strncpy(dst, src, size);
}

void OVIBC_010_function2(char* src, int size) {
  char dst2[5];
  strncpy(dst2, src, size);
}


void OVIBC_010_function3(int size) {
  if(size < 10) {
    char src1[] = "0123456789"; // sizeof(src1) == 11
    OVIBC_010_function1(src1, size); //It's ok.

    OVIBC_010_function2(src1, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
    
  }
}

