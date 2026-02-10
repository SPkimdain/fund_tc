#include <stdlib.h>
#include <string.h>

/* UAF_020 - library test */
void UAF_020_function() {
  const char src[] = "abc";
  char* dst = (char*)malloc(10);

  if(dst == 0) {
    return;
  }

  free(dst);

  strcpy(dst, src); //@violation USE_AFTER_FREE
    
}
