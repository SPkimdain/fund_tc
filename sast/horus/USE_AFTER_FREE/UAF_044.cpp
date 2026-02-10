#include <stdlib.h>

/* UAF_044 - use after free with lambda */
void UAF_044_function() {
  int * ptr = (int*)malloc(4);
  
  if(ptr == 0) {
    return;
  }

  auto&& UAF_044_lambda = [ptr]() {
    free(ptr);
    return;
  };

  UAF_044_lambda();

  *ptr = 1; //@violation USE_AFTER_FREE
 
}
