#include <stdlib.h>

/* FNH_001 - simple free non heap. */
void FNH_001_function() {
  int x = 0;
  free(&x); //@violation FREE_NON_HEAP
}

