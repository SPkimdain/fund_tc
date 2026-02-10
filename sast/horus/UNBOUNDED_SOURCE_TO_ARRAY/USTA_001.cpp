#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* USTA_001 - simple case */

int USTA_001_function(int argc, char *argv[]) {
  char cmdline[4096] = { 0, };
  char *filename;
  filename = getenv("SHAREDFILE");

  char* ptr = cmdline;
  
  strcat(ptr, filename);  //@violation UNBOUNDED_SOURCE_TO_ARRAY 
  
  return 0;
}
