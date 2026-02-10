#include <stdlib.h>

/* UAF_013 - for2 */
void UAF_013_function(int value, int value2) {
  int p = 100;
  int* ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  *ptr = 10;
  int ret = 0;

  for(int i = 0; i < 1; i++) {
    free(ptr);

    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ret = *ptr; //@violation USE_AFTER_FREE
      }
    }
  }
}
