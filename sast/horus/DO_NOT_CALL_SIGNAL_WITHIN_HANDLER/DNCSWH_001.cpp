#include <signal.h>

/* DNCSWH_001 - simple test */ 

void DNCSWH_001_handler1(int signum) {
  if(signal(signum, SIG_DFL) == SIG_ERR) { //It's ok.
    return;
  }
}

void DNCSWH_001_handler2(int signum) {
  if(signal(signum, DNCSWH_001_handler1) == SIG_ERR) { //@violation DO_NOT_CALL_SIGNAL_WITHIN_HANDLER    
    return;
  }
}

int DNCSWH_001_function() {
  if(signal(SIGINT, DNCSWH_001_handler1) == SIG_ERR) {
    return 0;
  }
  
  if(signal(SIGSEGV, DNCSWH_001_handler2) == SIG_ERR) {
    return 0;
  }

  return 1;
}
