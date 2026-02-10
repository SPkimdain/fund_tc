#include <stdlib.h>

/* UAF_003 - if branch1 */
void UAF_003_function(int arg) {
  int* ptr = (int*)malloc(4);
  
  if(ptr == 0) {
    return;
  }

  if(arg == 10) {
    *ptr = 10;
    free(ptr); //It's ok.
  }
  else {
    free(ptr);
    *ptr = 20; //@violation USE_AFTER_FREE    
  }

}
