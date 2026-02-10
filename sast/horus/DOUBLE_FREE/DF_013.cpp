#include <stdlib.h>
/* DF_013 - alloc & free function call. */

void DF_013_function1(int index) {
  if(index < 10) {
    return;
  }

  int* arr = new int[index];
  arr[0] = 10;

  delete[] arr;
}

void DF_013_function2() {
  DF_013_function1(15);
}

void DF_013_function3() {
  int x = 5;
  do {
    DF_013_function2(); //It's ok.
    x--;
  } while(x > 0);

  return;
}

int DF_013_function4(int flag) {
  int * ptr = (int*)malloc(4);
  free(ptr);
  free(ptr); //@violation DOUBLE_FREE
  return flag;
}


