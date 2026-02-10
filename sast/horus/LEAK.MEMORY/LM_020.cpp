#include <stdlib.h>
#include <string.h>

/* LM_020 - strcpy from opus */
void LM_020_function(char* src) {
  unsigned int size = strlen(src) + 1;
  char* dst = (char*)malloc(size);
  
  if(dst == 0) {
    return;
  }
  
  strcpy(dst, src); 
  
  return;
} //@violation LEAK.MEMORY
