#include <string.h>

/* MWOR_003 - simple case2 */

void MWOR_003_function() {
  char p[100] = { 0, };
  char *pt1 = p;
  char *pt2;
  pt2 = p;

  

  pt1 = pt1 + 7;
  memcpy(pt2, pt1, 3); //It's ok.

  pt1 = p + 3;
  memcpy(pt2, pt1, 5);  //@violation MEMCPY_WITH_OVERLAPPING_REGIONS
}

