#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ODIBC_009 - strncpy2 */
void ODIBC_009_function(int offset){
  char* buf = new char[25];
  if(buf == 0) {
    return;
  }
  char *str = "0123456789012345678901234567890123456789";

  if(offset < 10) { //[min, 9]
    offset+= 20; //[min, 29]
    strncpy(buf, str, offset); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }

  delete[] buf;
}

