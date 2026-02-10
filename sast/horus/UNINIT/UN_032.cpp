#pragma warning(disable : 4700)

#include <stdio.h>

/* UN_032 - printf from opus */
void UN_032_function() {
  int x;
  printf("%d", x); //@violation UNINIT
  return;
}
