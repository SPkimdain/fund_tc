#include <string.h>

/* OVI_010 - boundary check */
void OVI_010_function1(char* src) {
  char dst[5];
  strcpy(dst, src);
}

void OVI_010_function2(char* src) {
  char dst2[5];
  strcpy(dst2, src); 
}


void OVI_010_function3() {
  char src1[] = "1234"; //sizeof(src1) == 5, len = 4
  char src2[] = "12345"; //sizeof(src2) == 6, len = 5
  
  OVI_010_function1(src1); //It's ok.
  OVI_010_function2(src2); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}

