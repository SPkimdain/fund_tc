// @checker SIGNAL_HANDLER_USES_NON_VOLATILE_VARIABLE

#include <signal.h>

sig_atomic_t i;
sig_atomic_t j;
volatile sig_atomic_t k;

void handler1(int signum) {   // @violation SIGNAL_HANDLER_USES_NON_VOLATILE_VARIABLE
  i = 0;
}


void handler2(int signum) {   // @violation SIGNAL_HANDLER_USES_NON_VOLATILE_VARIABLE
  j = 0;
}


void handler3(int signum) {
  k = 0;
}


int noncompliant1(void) {
  i = 1;
  signal(SIGINT, handler1);
  while (i) {
    /* do something */
  }
  return 0;
}


int noncompliant2(void) {
  i = 1;
  signal(SIGINT, handler2);
  while (*(volatile sig_atomic_t *) &i) {
    /* do something */
  }
  return 0;
}


int compliant(void) {
  k = 1;
  signal(SIGINT, handler3);
  while (k) {
    /* do something */
  }
  return 0;
}
