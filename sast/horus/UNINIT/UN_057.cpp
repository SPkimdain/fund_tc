#include <stdarg.h>

/* UN_057 - va_list */

int UN_057_function1(va_list ap) {
  int x = 0;
  x++;
  return 0;
}

void UN_057_function2(int value, ...) {
  va_list ap;
  va_start(ap, value);
  
  int x = UN_057_function1(ap); //It's ok.

  va_end(ap);
  
  int a;
  int b;
  b = a; //@violation UNINIT

}
