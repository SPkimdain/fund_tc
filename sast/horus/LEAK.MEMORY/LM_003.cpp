#include <stdlib.h>

/* LM_003 - if branch1 */
void LM_003_function(int arg) {
  int* ptr = (int*)malloc(4);
  
  if(ptr == 0) {
    return;
  }

  if(arg == 10) {
    *ptr = 10;
    free(ptr);
  }
  else {
    return; 
  } //@violation LEAK.MEMORY

}
