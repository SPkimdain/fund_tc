
/* AHCE_006 - multiple exit */
#include <stdio.h>
#include <stdlib.h>

void AHCE_006_logic2(int value) {
  if(value > 10) {
    value--;
  }
  else {
    value = value + 100;
  }

  if(value > 100) {
    abort(); //Here.
  }
  else if(value < 100 && value > 10) {
    exit(0);
  }
  else {
    value++;
  }

}

int AHCE_006_logic3(int flag) {
  switch(flag) {
  case 0:
    return 0;

  case 10:
    return flag + 10;

  case 20:
    AHCE_006_logic2(50);
    break;
  
  default:
    break;
  }
  
  return 0;
}

void AHCE_006_exit(void) {
  int ret = AHCE_006_logic3(10); //It's ok.

  ret = AHCE_006_logic3(ret); //@violation ATEXIT_HANDLER_CALLS_EXIT	
  return;
}

int AHCE_006_function1(void) {
  if(atexit(AHCE_006_exit) != 0) { // Source 
    /* Handle error */
  }

  return 0;
}
