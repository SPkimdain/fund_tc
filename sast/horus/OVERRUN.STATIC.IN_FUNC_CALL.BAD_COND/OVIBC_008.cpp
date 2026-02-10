#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* OVIBC_008 - str32 from opus */
void OVIBC_008_function1(char *source, int size) {
  char ntbs[5] = "abcd"; //sizeof(ntbs) == 5
  ntbs[sizeof(ntbs) - 1] = '\0';

  strncpy(ntbs, source, size); 
}

void OVIBC_008_function2(int size) {
  char *b = "123456789";
  if(size < 10) {
    OVIBC_008_function1(b, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
  }
}
