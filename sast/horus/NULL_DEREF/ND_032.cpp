#include <string.h>

/* ND_032 - strcpy from opus */
void ND_032_function() {
  char *str = 0;
  char *dst = "abc";
  strcpy(dst, str); //@violation NULL_DEREF
  return;
}
