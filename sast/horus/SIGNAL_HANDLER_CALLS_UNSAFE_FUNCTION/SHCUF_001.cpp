
/* SHCUF_001 - simple test */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
 
char *SHCUF_001_Info = NULL;
 
void SHCUF_001_handler(int signum) {
  fprintf(stderr, SHCUF_001_Info); // @violation SIGNAL_HANDLER_CALLS_UNSAFE_FUNCTION
}
 
int SHCUF_001_function2() {
  if (signal(SIGINT, SHCUF_001_handler) == SIG_ERR) {	
    /* Handle error */
  }
  SHCUF_001_Info = (char*)malloc(1024);
  if(SHCUF_001_Info == NULL) {
    /* Handle Error */
  }
  
  free(SHCUF_001_Info);     
  return 0;
}

