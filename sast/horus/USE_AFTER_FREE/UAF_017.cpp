#include <stdlib.h>

/* UAF_017 - unary operator order */
void UAF_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int* arr[2];

  arr[0] = (int*)malloc(4);

  if(arr[0] == 0) {
    return;
  }

  arr[1] = (int*)malloc(2);

  if(arr[1] == 0) {
    free(arr[0]);
    return;
  }

  *arr[0] = 10;
  *arr[1] = 2;
  free(arr[1]);
  int index = 0;

  ptr = arr[index++]; // index + 1 after assign arr[0].

  ret += *ptr; // It's ok.

  index = 0;
  ptr = arr[++index]; // assign arr[1] after index + 1.
  ret += *ptr; // @violation USE_AFTER_FREE

  free(arr[0]);
}
