#include <signal.h>

/* DNCSWH_002 - simple test2 */

void DNCSWH_002_handler1(int signum) {
  int ret = signum;
  ret++;
  return;
}

void DNCSWH_002_handler2(int signum) {
  if(signal(signum, SIG_DFL) == SIG_ERR) { //It's ok.
    return;
  }

  if(signal(SIGABRT, DNCSWH_002_handler1) == SIG_ERR) { //@violation DO_NOT_CALL_SIGNAL_WITHIN_HANDLER    
    return;
  }
}

int DNCSWH_002_function() {
  if(signal(SIGSEGV, DNCSWH_002_handler2) == SIG_ERR) {
    return 0;
  }

  return 1;
}
