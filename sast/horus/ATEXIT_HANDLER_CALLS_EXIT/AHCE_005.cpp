
/* AHCE_005 - _exit function test */
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#define EXIT _exit

#else

#define EXIT exit

#endif

void AHCE_005_exit1(void) {
  int x = 0;
  x++;
  return;
}

void AHCE_005_exit2(void) {
  
  EXIT(0); //@violation ATEXIT_HANDLER_CALLS_EXIT	
  return;
}

int AHCE_005_function1(void) {
  if(atexit(AHCE_005_exit1) != 0) {
    /* Handle error */
  }
  if(atexit(AHCE_005_exit2) != 0) { // Source 
    /* Handle error */
  }

  return 0;
}
