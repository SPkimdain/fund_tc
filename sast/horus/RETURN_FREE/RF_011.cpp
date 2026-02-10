#include <stdlib.h>
#include <string.h>

/* RF_011 - strcmp check. */
int* RF_011_function(char* buf) {
  int* ptr = (int*)malloc(4); 
  free(ptr);

  char* check = buf;
  
  return ptr; //@violation RETURN_FREE
}
