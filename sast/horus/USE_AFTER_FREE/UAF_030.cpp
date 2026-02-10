#include <string.h>
#include <stdlib.h>

/* UAF_030 - mem30 from opus */
void UAF_030_function(const char *argv[]){
  char *buff;

  buff = (char *)malloc(256);
  if(!buff) {
    /* Handle error condition */
    return;
  }
  /* ... */
  free(buff);
  /* ... */
  strncpy(buff, argv[1], 256 - 1); //@violation USE_AFTER_FREE
  return;
}
