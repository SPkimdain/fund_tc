//@checker PREVENT_SENSITIVE_DATA_WRITE_TO_DISK
#include <memory.h>
#include <stdlib.h>

extern int memset_s(char* s, char dl, int size);

void PRVSDWTD_001_function(int size) {
  
  char *secret;
  secret = (char *)malloc(size+1);
  if (!secret) {
    /* Handle error */
  }
  /* Perform operations using secret... */
  memset_s(secret, '\0', size+1); //@violation PREVENT_SENSITIVE_DATA_WRITE_TO_DISK
  free(secret);
  secret = NULL;
  
}

