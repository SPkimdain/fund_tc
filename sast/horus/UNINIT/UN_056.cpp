#include <memory.h>

/* UN_056 - memset check */
void UN_056_function() {
  int arr[100];
  int arr2[100];

  memset(arr, 0, 100 * sizeof(int));

  int x = arr[10]; //It's ok.
  int y = arr2[10]; //@violation UNINIT
}
