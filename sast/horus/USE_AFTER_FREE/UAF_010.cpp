#include <stdlib.h>

/* UAF_010 - Complex expression */
void UAF_010_function() {
  int *ptr1 = (int*)malloc(4);

  if(ptr1 == 0) {
    return;
  }

  int *ptr2 = (int*)malloc(4);

  if(ptr2 == 0) {
    free(ptr1);
    return;
  }

  int *ptr3 = (int*)malloc(6);

  if(ptr3 == 0) {
    free(ptr1);
    free(ptr2);
    return;
  }

  *ptr1 = 10;
  *ptr2 = 20;
  *ptr3 = 30;

  free(ptr3);
  int ret = 0;

  ret = *ptr1 +  //No problem.
    *ptr1 -
    *ptr2;

  ret = *ptr1 +
    *ptr2 -
    (*ptr3 + 1); //@violation USE_AFTER_FREE


  free(ptr1);
  free(ptr2);
}
