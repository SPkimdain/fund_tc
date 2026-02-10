#include <stdlib.h>

/* FNH_003 - if branch1 */
void FNH_003_function(int arg) {
  int value = 10;
  if(arg == 10) {
    free(&value);  //@violation FREE_NON_HEAP
  }
  else {
    return;
  }

}
