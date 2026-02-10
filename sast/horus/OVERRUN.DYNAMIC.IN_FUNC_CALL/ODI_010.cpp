#include <string.h>

/* ODI_010 - boundary check */
char* ODI_010_function3(int size) {
  return new char[size];
}

void ODI_010_function1(char* src) {
  char* dst = ODI_010_function3(5);
  if(dst == 0) {
    return;
  }

  strcpy(dst, src);
  delete[] dst;
}

void ODI_010_function2(char* src) {
  char* dst2 = ODI_010_function3(6);
  if(dst2 == 0) {
    return;
  }

  strcpy(dst2, src); 
  delete[] dst2;
}

void ODI_010_function4() {
  char src1[] = "1234"; //sizeof(src1) == 5, len = 4
  char src2[] = "1234567"; //sizeof(src2) == 8, len = 7
  
  ODI_010_function1(src1); //It's ok.
  ODI_010_function2(src2); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
}

