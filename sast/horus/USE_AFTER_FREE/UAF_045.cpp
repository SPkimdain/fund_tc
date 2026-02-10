#include <stdlib.h>

/* UAF_045 - use after free with lambda */
void UAF_045_function() {
  int* ptr = new int(100);
  
  if(ptr == 0) {
    return;
  }

  auto&& UAF_045_lambda = [](int* data) {
    delete data;   
  };

  UAF_045_lambda(ptr);

  *ptr = 1; //@violation USE_AFTER_FREE
 
}
