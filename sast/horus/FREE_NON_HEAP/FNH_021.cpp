#include <stdlib.h>

/* FNH_021 - free non heap with lambda. */
void FNH_021_function(int* obj) {
  int x = 0;
  int* ptr = &x;

  auto&& FNH_021_lambda = [](int* arg) {
    free(arg);
  };

  FNH_021_lambda(obj); //It's ok.
  FNH_021_lambda(ptr);//@violation FREE_NON_HEAP
}

