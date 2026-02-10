
/* DNRSH_003 - simple test */

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t DNRSH_003_denom;

void DNRSH_003_handler(int s) {
  /* Fix the offending volatile */
  if(DNRSH_003_denom == 0) {
    DNRSH_003_denom = 1; //It's ok. handler is SIGSEGV.
  }
}

void DNRSH_003_handler2(int s) {
  /* Fix the offending volatile */
  if(DNRSH_003_denom == 0) {
    DNRSH_003_denom = 1; //@violation DO_NOT_RETURN_SIGNAL_HANDLERS
  }
}

int DNRSH_003_function(int argc, char *argv[]) {
  if(argc < 2) {
    return 0;
  }

  char *end = NULL;
  long temp = strtol(argv[1], &end, 10);

  if(end == argv[1] || 0 != *end ||
    errno == ERANGE) {
    /* Handle error */
  }

  DNRSH_003_denom = (sig_atomic_t)temp;

  signal(SIGINT, DNRSH_003_handler);

  signal(SIGFPE, DNRSH_003_handler2);

  long result = 100 / (long)DNRSH_003_denom;
  return 0;
}
