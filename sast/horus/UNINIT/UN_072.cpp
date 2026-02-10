#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* UN_072 - array, loop3 */
void UN_072_function() {
  double* data;
  double arr[10];

  data = arr;
  for(int i = 0; i < 10; i++) {
    printf("%ld", data[i]); //@violation UNINIT
  }

  return;
}
