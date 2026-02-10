
/* AHCE_004 - longjmp */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf AHCE_004_jmpEnv;

void AHCE_004_exit(void) {
  longjmp(AHCE_004_jmpEnv, 1); //@violation ATEXIT_HANDLER_CALLS_EXIT	
  return;
}

int AHCE_004_function1(void) {

  if(atexit(AHCE_004_exit) != 0) {
    /* Handle error */
  }

  if(setjmp(AHCE_004_jmpEnv) == 0) {
    return 0;
  }

  return 1;
}

