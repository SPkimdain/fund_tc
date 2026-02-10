
/* SHCUF_003 - simple test3 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>

jmp_buf SHCUF_003_jmpEnv;

void SHCUF_003_function1() {
  longjmp(SHCUF_003_jmpEnv, 1);
}

void SHCUF_003_handler(int signum) {
  time_t timer;
  time(&timer); //It's ok.

  SHCUF_003_function1(); // @violation SIGNAL_HANDLER_CALLS_UNSAFE_FUNCTION  
}

int SHCUF_003_function2() {
  if(signal(SIGABRT, SHCUF_003_handler) == SIG_ERR) {
    /* Handle error */
  }

  if(setjmp(SHCUF_003_jmpEnv) == 0) {
    return 1;
  }

  return 0;
}


