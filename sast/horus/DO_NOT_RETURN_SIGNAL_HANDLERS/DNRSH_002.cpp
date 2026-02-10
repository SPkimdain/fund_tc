
/* DNRSH_002 - simple test2 */

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>

volatile int* DNRSH_002_ptr;
int DNRSH_002_value = 10;

extern int* DNRSH_002_function2();

void DNRSH_002_handler(int s) {
  /* Fix the offending volatile */
  if(DNRSH_002_ptr == 0) {
    DNRSH_002_ptr = &DNRSH_002_value; //@violation DO_NOT_RETURN_SIGNAL_HANDLERS
  }
}

int DNRSH_002_function(int argc, char *argv[]) {
  if(argc < 2) {
    return 0;
  }

  char *end = NULL;
  int* temp = DNRSH_002_function2();

  DNRSH_002_ptr = temp;

  signal(SIGSEGV, DNRSH_002_handler);

  int result = *DNRSH_002_ptr;
  return 0;
}
