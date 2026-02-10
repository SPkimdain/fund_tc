#include <string.h>
#include <stdlib.h>

void OD_002_function1(char *buf, char n) {
  buf[n+2] = 0; 
}

int OD_002_function2() {
  char *dest;
  dest = (char*)malloc(12);

  if(dest == 0) {
    return 0;
  }

  OD_002_function1(dest + 8, 4); //@violation OVERRUN.DYNAMIC
  free(dest);
  return 0;
}
