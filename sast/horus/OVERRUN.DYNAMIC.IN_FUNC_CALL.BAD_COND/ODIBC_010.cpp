#include <string.h>

/* ODIBC_010 - boundary check */
char* ODIBC_010_function3(int size) {
  return new char[size];
}

void ODIBC_010_function1(char* src, int size) {
  char* dst = ODIBC_010_function3(10);
  if(dst == 0) {
    return;
  }

  strncpy(dst, src, size);
  
  delete[] dst;
}

void ODIBC_010_function2(char* src, int size) {
  char* dst2 = ODIBC_010_function3(5);
  if(dst2 == 0) {
    return;
  }

  strncpy(dst2, src, size);
  
  delete[] dst2;
}


void ODIBC_010_function4(int size) {
  if(size < 10) {
    char src1[] = "0123456789"; // sizeof(src1) == 11
    ODIBC_010_function1(src1, size); //It's ok.

    ODIBC_010_function2(src1, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    
  }
}

