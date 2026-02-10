
/* AHCE_003 - complex2 */
#include <stdio.h>
#include <stdlib.h>

void AHCE_003_function1(int flag) {
  if(flag > 10) {
    abort();
  }
}

void AHCE_003_function2(int flag) {
  AHCE_003_function1(flag);
}

void AHCE_003_function3(int val) {
  val++;
  val++;

  AHCE_003_function2(val);
}

void AHCE_003_exit2(void) {

  AHCE_003_function3(9); //@violation ATEXIT_HANDLER_CALLS_EXIT	
  return;
}

int AHCE_003_function4(void) {
  if(atexit(AHCE_003_exit2) != 0) { // Source 
    /* Handle error */
  }
  return 0;
}
