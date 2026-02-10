#include <string.h>

/* ODI_004 - simple strcpy */
void ODI_004_function() {
  char* dst = new char[5];
  if(dst == 0) {
    return;
  }

  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5

  strcpy(dst, src2); //It's ok.
  
  strcpy(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;
}
