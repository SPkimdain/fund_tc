#include <string.h>
#include <stdlib.h>

void UDD_002_function1(char *buf, char n) {
  buf[n+2] = 0; 
}

int UDD_002_function2() {
  char *dest;
  dest = (char*)malloc(12);

  if(dest == 0) {
    return 0;
  }

  UDD_002_function1(dest + 8, -11); //@violation UNDERRUN.DYNAMIC
  free(dest);
  return 0;
}
