#include <stdlib.h>

/* FNH_010 - global variable2 */
int FNH_010_variable[256];

void FNH_010_function(){

  free(FNH_010_variable); //@violation FREE_NON_HEAP
}

