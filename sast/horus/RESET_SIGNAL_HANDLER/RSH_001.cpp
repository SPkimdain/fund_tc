/* RSH_001 - simple test */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void RSH_001_handler1(int signum) {
  abort(); //It's ok.
}

void RSH_001_handler2(int signum) {
  int ret = 0;
  if(signal(signum, RSH_001_handler2) == SIG_ERR) { //@violation RESET_SIGNAL_HANDLER
    ret++;
  }
}

int RSH_001_function() {
  if(signal(SIGABRT, RSH_001_handler2) == SIG_ERR) {
    return -1;
  }

  return 0;
}
