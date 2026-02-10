#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* OVI_009 - strncpy with strlen */
void OVI_009_function(){
  char *str = "01234567890123456789";
  char buf[19];
  unsigned int len = strlen(str); //20

  strncpy(buf, str, len); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}

