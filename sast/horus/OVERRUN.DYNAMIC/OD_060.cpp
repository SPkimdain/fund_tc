#include <string.h>
#include <stdlib.h>

/* OD_060 - trace loop value */

void OD_060_function1(char *buf, char n) {
  buf[n] = 0;
}

int OD_060_function2() {
  char *dest;
  dest = (char*)malloc(12);

  if(dest == 0) {
    return 0;
  }
  
  int ret = 0;
  int i;
  for(i = 0; i <= 11; i++) {
    ret = i;
  }

  /* i is 12 */
  OD_060_function1(dest, i); //@violation OVERRUN.DYNAMIC
  free(dest);
  return ret;
}
