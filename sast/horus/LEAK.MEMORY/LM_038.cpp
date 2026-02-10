#include <stdlib.h>

/* LM_038 - mem32 from opus */
void LM_038_function1(){

  char *p = (char*)malloc(100);
  unsigned int new_size = 10  /* nonzero size */;

  char * np = (char*)realloc(p, new_size);
  if(np == 0)   {
    /* Handle error */
    free(p);
    return;
  }
  return;
} //@violation LEAK.MEMORY
