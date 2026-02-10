#include <stdlib.h>

/* UAF_012 - for */
void UAF_012_function() {
  int* arr[3];
  
  for(int i = 0; i < 3; i++) {
    arr[i] = (int*)malloc(2);
    if(arr[0] == 0) {
      return;
    }
  }

  for(int i = 0; i < 3; i++) {
    free(arr[i]);
  }

  *arr[0] = 10; //@violation USE_AFTER_FREE  
}

