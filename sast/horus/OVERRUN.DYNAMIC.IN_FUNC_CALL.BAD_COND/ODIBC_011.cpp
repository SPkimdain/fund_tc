#include <string.h>

/* ODIBC_011 - global variable */
char* ODIBC_011_Buf = 0;

void ODIBC_011_function(int size) {
  char src[] = "01234678"; //sizeof(src) == 10

  ODIBC_011_Buf = new char[4];
  if(ODIBC_011_Buf == 0) {
    return;
  }


  if(size < 10) {
    strncpy(ODIBC_011_Buf, src, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }
  
  delete[] ODIBC_011_Buf;
  ODIBC_011_Buf = 0;
}
