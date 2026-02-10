#include <stdio.h>
#include <stdlib.h>

/* DF_008 - mem31 from opus */
void DF_008_function(){
  int size = 100;
  char *p = (char*)malloc(100);

  /* p is a pointer to dynamically allocated memory */
  char *p2 = (char*)realloc(p, size);
  if(p2 == 0) {
    free(p); //It's ok.
    return;
  }
  else {
    free(p); //@violation DOUBLE_FREE
  }
  free(p2);


}
