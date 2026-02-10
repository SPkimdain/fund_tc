#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* OVIBC_009 - strncpy2 */
void OVIBC_009_function(int offset){
  char *str = "0123456789012345678901234567890123456789";
  char buf[25];
  if(offset < 10) { //[min, 9]
    offset+= 20; //[min, 29]
    strncpy(buf, str, offset); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}

