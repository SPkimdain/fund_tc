#include <stdlib.h>

/* FNH_008 - mem34 from opus */
void FNH_008_function(void) {
  char buf[256];
  char *p;
  /* ... */
  p = (char *)realloc(buf, 2 * 256);  //@violation FREE_NON_HEAP
  /* ... */
  free(p);
  return;
}
