#include <string.h>

/* MWOR_002 - simple case2 */

void MWOR_002_function() {
  char p[100];
  char *pt1 = p;
  char *pt2;
  pt2 = p + 2;

  strcpy(p, "string copy");

  strcpy(pt2, pt1);  //@violation MEMCPY_WITH_OVERLAPPING_REGIONS
}

