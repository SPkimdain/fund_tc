#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TOI_009 - strncpy with strlen */
struct TOI_009_Class {
  char buf[19];
};

typedef TOI_009_Class TOI_009_Typedef;

void TOI_009_function(){
  char *str = "01234567890123456789";
  TOI_009_Typedef obj;
  unsigned int len = strlen(str); //20

  strncpy(obj.buf, str, len); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}

