/* RSH_002 - set default action  */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void RSH_002_handler2(int signum) {
  if(signal(signum, SIG_DFL) == SIG_ERR) { //It's ok.
    return;
  }

  if(signal(signum, RSH_002_handler2) == SIG_ERR) { //@violation RESET_SIGNAL_HANDLER
    return;
  }
}

int RSH_002_function() {
  if(signal(SIGABRT, RSH_002_handler2) == SIG_ERR) {
    return -1;
  }
  
  
  return 0;
}
