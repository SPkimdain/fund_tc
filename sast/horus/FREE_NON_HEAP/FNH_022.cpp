#include <stdlib.h>

/* FNH_022 - free non heap with lambda case2. */
void FNH_022_function(int* obj) {
  int x = 0;
  int* ptr = &x;

  auto&& FNH_022_lambda1 = [obj]() {
    free(obj);
  };

  auto&& FNH_022_lambda2 = [&x]() {
    free(&x);
  };

  FNH_022_lambda1(); //It's ok.
  
  FNH_022_lambda2();//@violation FREE_NON_HEAP

}

