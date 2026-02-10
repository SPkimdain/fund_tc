
/* AHCE_001 - simple test */
#include <stdio.h>
#include <stdlib.h>
 
void AHCE_001_exit1(void) {
  int x = 0;
  x++;
  return;
}
 
void AHCE_001_exit2(void) {
	exit(0); //@violation ATEXIT_HANDLER_CALLS_EXIT	
	return;
}
 
int AHCE_001_function1(void) {
  if (atexit(AHCE_001_exit1) != 0) {
    /* Handle error */
  }
  if (atexit(AHCE_001_exit2) != 0) { // Source 
    /* Handle error */
  }
  
  return 0;
}
