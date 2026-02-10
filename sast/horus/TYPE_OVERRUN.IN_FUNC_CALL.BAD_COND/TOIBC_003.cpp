#include <string.h>

/* TOIBC_003 - simple memmove */
struct TOIBC_003_Class {
  char str[11];
};


void TOIBC_003_function(int flag, int index) {
  TOIBC_003_Class obj;
  memcpy(obj.str, "0123456789", 11);

  if(flag == 1) {
    if(index < 6) {
      memmove(obj.str + index, obj.str + 2, 5); //It's ok.
    }
  }
  else {
    if(index < 10) {
      memmove(obj.str + index, obj.str + 2, 5); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    }
  }
}
