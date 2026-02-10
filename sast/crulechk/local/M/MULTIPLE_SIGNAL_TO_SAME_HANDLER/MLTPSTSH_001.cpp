//@checker MULTIPLE_SIGNAL_TO_SAME_HANDLER

#include <signal.h>

extern void MLTPSTSH_001_handler(int sig);


void MLTPSTSH_001_function() {
  signal(SIGINT, MLTPSTSH_001_handler);
  signal(SIGILL, MLTPSTSH_001_handler); //@violation MULTIPLE_SIGNAL_TO_SAME_HANDLER
}
