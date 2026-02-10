#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ODI_009 - strncpy with strlen */
void ODI_009_function(){
  char* buf = new char[19];
  if(buf == 0) {
    return;
  }

  char *str = "01234567890123456789";

  unsigned int len = strlen(str); //20

  strncpy(buf, str, len); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  
  delete[] buf;
}

