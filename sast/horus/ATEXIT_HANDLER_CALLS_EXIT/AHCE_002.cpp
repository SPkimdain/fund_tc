
/* AHCE_002 - complex1 */
#include <stdio.h>
#include <stdlib.h>

void AHCE_002_function1(int flag) {
  if(flag > 10) {
    exit(0);
  }
}
 
void AHCE_002_exit2(void) {
  int ret = 0;
  AHCE_002_function1(0); //It's ok.
  
  ret++;  
  
  AHCE_002_function1(20); //@violation ATEXIT_HANDLER_CALLS_EXIT	
	return;
}
 
int AHCE_002_function2(void) {
  if (atexit(AHCE_002_exit2) != 0) { // Source 
    /* Handle error */
  }
  return 0;
}
