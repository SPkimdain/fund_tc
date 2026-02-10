#include <string.h>

/* MWOR_001 - simple case */

void MWOR_001_function(){
  char p[100];
  char *pt1 = p;
  char *pt2;
  pt2 = p;
  
  strcpy(p, "string copy");
  
  strcpy(pt2, pt1);  //@violation MEMCPY_WITH_OVERLAPPING_REGIONS
}

