#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TOIBC_009 - strncpy2 */
struct TOIBC_009_Class {
  char buf[25];
};


void TOIBC_009_function(int offset){
  char *str = "0123456789012345678901234567890123456789";
  TOIBC_009_Class obj;
  if(offset < 10) { //[min, 9]
    offset+= 20; //[min, 29]
    strncpy(obj.buf, str, offset); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}

