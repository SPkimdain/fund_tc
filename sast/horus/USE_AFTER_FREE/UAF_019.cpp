#include <stdlib.h>

/* UAF_019 - short circuit */
bool UAF_019_function1(int* ptr) {
  free(ptr);
  return true;
}

void UAF_019_function2() {
  int* ptr = (int*)malloc(4);

  if(ptr == 0) {
    return;
  }

  int x = 10;
  int compareValue = 20;
  int ret = 0;
  *ptr = 20;

  free(ptr);
  *ptr = 10; //@violation USE_AFTER_FREE
}

