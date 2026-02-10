
/* DNRSH_001 - simple test */

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t DNRSH_001_denom;

void DNRSH_001_handler(int s) {
  /* Fix the offending volatile */
  if(DNRSH_001_denom == 0) {
    DNRSH_001_denom = 1; //@violation DO_NOT_RETURN_SIGNAL_HANDLERS
  }
}

int DNRSH_001_function(int argc, char *argv[]) {
  if(argc < 2) {
    return 0;
  }

  char *end = NULL;
  long temp = strtol(argv[1], &end, 10);

  if(end == argv[1] || 0 != *end ||
    errno == ERANGE) {
    /* Handle error */
  }

  DNRSH_001_denom = (sig_atomic_t)temp;
  
  signal(SIGFPE, DNRSH_001_handler);

  long result = 100 / (long)DNRSH_001_denom;
  return 0;
}
