#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* OVI_008 - str32 from opus */
void OVI_008_function1(char *source, int size) {
  char ntbs[5] = "abcd"; //sizeof(ntbs) == 5
  ntbs[sizeof(ntbs) - 1] = '\0';

  strncpy(ntbs, source, size); 
}

void OVI_008_function2() {
  char *b = "123456789";
  OVI_008_function1(b, 6); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
