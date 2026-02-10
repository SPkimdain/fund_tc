#include <string.h>

/* ODI_011 - global variable */
char* ODI_011_Buf = 0;

void ODI_011_function() {
  char src[] = "abcde"; // sizeof(src) == 6
  ODI_011_Buf = new char[4];
  if(ODI_011_Buf == 0) {
    return;
  }
  strcpy(ODI_011_Buf, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] ODI_011_Buf;
  ODI_011_Buf = 0;
}
