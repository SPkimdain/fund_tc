#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ND_076_MAX 1024

/* ND_076 - fgets dereference test. */
char* ND_076_function(int size) {
  char* ptr = 0;
  if(size > 0) {
    ptr = (char*)calloc(size, sizeof(int));
    if(ptr == 0) {
      return 0;
    }
  }
  
  fgets(ptr, ND_076_MAX, stdin); //@violation NULL_DEREF

  return ptr;
}
