/* Ignore bit calcaulation. */

#define FLAG 1 | 2 | 8 | 16

void CAV_022_function() {
  int counter = 0;
  unsigned long dwFlag = 0;
  

  dwFlag = -100; //@violation CAST_ALTERS_VALUE.EXT
}

