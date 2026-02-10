#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* TOIBC_008 - str32 from opus */
struct TOIBC_008_Class {
  char ntbs[5];
};

void TOIBC_008_function1(char *source, int size) {
  TOIBC_008_Class obj;
  obj.ntbs[sizeof(obj.ntbs) - 1] = '\0';

  strncpy(obj.ntbs, source, size);
}

void TOIBC_008_function2(int size) {
  char *b = "123456789";
  if(size < 10) {
    TOIBC_008_function1(b, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}
