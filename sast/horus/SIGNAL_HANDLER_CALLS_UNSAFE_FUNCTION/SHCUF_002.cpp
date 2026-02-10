
/* SHCUF_002 - simple test2 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void log(const char* msg);

void SHCUF_002_handler(int signum) {
  time_t timer;
  time(&timer); //It's ok.
  
  log("something message"); // @violation SIGNAL_HANDLER_CALLS_UNSAFE_FUNCTION  
}

int SHCUF_002_function2() {
  if(signal(SIGABRT, SHCUF_002_handler) == SIG_ERR) {	
    /* Handle error */
  }

  return 0;
}

