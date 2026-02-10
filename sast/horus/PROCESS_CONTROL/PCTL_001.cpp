#include <stdlib.h>

#define RTLD_LAZY 0

extern void *dlopen(const char *filename, int flag);

/* PCTL_001 - simple case */

void PCTL_001_function() {
  char *filename;
  filename = getenv("SHAREDFILE"); 
  
  dlopen(filename, RTLD_LAZY); //@violation PROCESS_CONTROL

  return;
}
