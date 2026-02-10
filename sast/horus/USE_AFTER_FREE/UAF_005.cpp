#include <stdlib.h>

/* UAF_005 - switch branch  */
void UAF_005_function(int arg) {
  bool flag = false;
  int* ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    free(ptr);
    flag = true;
    break;
  default:
    break;
  }

  *ptr = 10; //@violation USE_AFTER_FREE
  if(flag == false) {
    free(ptr);
  }
}
