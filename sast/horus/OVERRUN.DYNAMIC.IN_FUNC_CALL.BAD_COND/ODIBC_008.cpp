#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ODIBC_008 - str32 from opus */
void ODIBC_008_function1(char *source, int size) {
  char* ntbs = new char[5];
  if(ntbs == 0) {
    return;
  }
  ntbs[5 - 1] = '\0';

  strncpy(ntbs, source, size); 

  delete[] ntbs;
}

void ODIBC_008_function2(int size) {
  char *b = "123456789";
  if(size < 10) {
    ODIBC_008_function1(b, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
  }
}
