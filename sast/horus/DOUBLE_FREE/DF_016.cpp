#include <stdlib.h>

/* DF_016 - global variable */
int* DF_016_Var = 0;
void DF_016_function1(int* ptr) {
  DF_016_Var = ptr;
}

void DF_016_function() {
  int * ptr = (int*)malloc(4);

  DF_016_function1(ptr); //Set the global variable.

  free(ptr);
  free(DF_016_Var); //@violation DOUBLE_FREE
}
