#include <string.h>

/* TOIBC_010 - boundary check */
struct TOIBC_010_Class {
  char dst[10];
  char dst2[5];
};

void TOIBC_010_function1(char* src, int size) {
  TOIBC_010_Class obj;
  strncpy(obj.dst, src, size);
}

void TOIBC_010_function2(char* src, int size) {
  TOIBC_010_Class obj;
  strncpy(obj.dst2, src, size);
}


void TOIBC_010_function3(int size) {
  if(size < 10) {
    char src1[] = "0123456789"; // sizeof(src1) == 11
    TOIBC_010_function1(src1, size); //It's ok.

    TOIBC_010_function2(src1, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    
  }
}

