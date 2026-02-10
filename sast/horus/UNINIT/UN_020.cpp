#pragma warning(disable : 4700)

#include <stdlib.h>

/* UN_020 - library test */
void UN_020_function(char *str) {
  char* endPtr;
  char* endPtr2;

  strtoul(str, &endPtr, 10); //UNINIT

  str = endPtr; //It's ok.
  str = endPtr2; //@violation UNINIT
}

