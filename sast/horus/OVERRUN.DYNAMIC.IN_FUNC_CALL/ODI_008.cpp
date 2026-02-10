#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ODI_008 - str32 from opus */
void ODI_008_function1(char *source, int size) {
  char* ntbs = new char[5];
  if(ntbs == 0) {
    return;
  }
  ntbs[5 - 1] = '\0';
  
  strncpy(ntbs, source, size);
  
  delete[] ntbs;
}

void ODI_008_function2() {
  char *b = "123456789";
  ODI_008_function1(b, 6); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
}
