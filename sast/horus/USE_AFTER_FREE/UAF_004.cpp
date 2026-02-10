#include <stdlib.h>

/* UAF_004 - if branch2 */
void UAF_004_function(int arg) {
  int* ptr1 = (int*)malloc(4);

  if(ptr1 == 0) {
    return;
  }

  if(arg == 10) {
    free(ptr1);
  }
  else {
    *ptr1 = 1;
  }

  *ptr1 = 10; //@violation USE_AFTER_FREE
  if(arg != 10) {
    free(ptr1);
  }
}
