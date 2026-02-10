/* DNASO_001 - simple */

#include <string.h>
#include <signal.h>
#include <memory.h>
#include <stdlib.h>

enum { MAX_MSG_SIZE = 24 };
int globalFlag;
volatile sig_atomic_t t;

void DNASO_001_handler(int signum) {
  globalFlag = 10; //@violation DO_NOT_ACCESS_SHARED_OBJECT_IN_HANDLER
  
  t = 10; //It's ok.
}

int DNASO_001_function(void) {
  signal(SIGINT, DNASO_001_handler);

  globalFlag = 5;

  /* Main code loop */

  return 0;
}
