#include <stdlib.h>

/* FNH_020 - double pointer */
class FNH_020_Class {
  void FNH_020_function1(int** p) {
    *p = (int*)malloc(sizeof(int));
  }

  void FNH_020_function2(int** p) {
    *p = &value;
  }

  int FNH_020_function3() {
    int* p = 0;
    FNH_020_function1(&p);
    if(p == 0) {
      return 0;
    }

    *p = 42;
    free(p); //It's ok.

    p = 0;
    FNH_020_function2(&p);
    *p = 100;
    free(p); //@violation FREE_NON_HEAP

    return 0;
  }

private:
  int value;
};

