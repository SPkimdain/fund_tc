#include <stdlib.h>

/* UAF_011 - Complex call expression */
int* UAF_011_function1(int value, int* ptr, int* ptr2) {
  if(value > 10) {
    return ptr;
  }
  else {
    return ptr2;
  }
}

void UAF_011_function2() {
  int value = 10;
  int value2 = 5;
  int *ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  int *ptr2 = (int*)malloc(4);

  if(ptr2 == 0) {
    free(ptr);
    return;
  }

  *ptr = 0;
  *ptr2 = 0;
  free(ptr2);

  int ret = 0;

  ret = *(UAF_011_function1(value + 5, ptr, ptr2)) +
    *(UAF_011_function1(20, ptr, ptr2)); // No problem.

  ret = *(UAF_011_function1(11, ptr, ptr2)) + // Ok.
    *(UAF_011_function1(value2 + 20, ptr, ptr2)) + // Ok.
    *(UAF_011_function1(value2, ptr, ptr2)); // @violation USE_AFTER_FREE

  free(ptr);
}
