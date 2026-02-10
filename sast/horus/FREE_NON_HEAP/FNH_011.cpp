#include <stdlib.h>

/* FNH_011 - global variable */
int FNH_011_Var = 10; 

void FNH_011_function() {
  free(&FNH_011_Var); //@violation FREE_NON_HEAP
}

