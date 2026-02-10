#include <stdlib.h>

/* FNH_006 - Access field  */
struct FNH_006_Struct {
  int value;
  int* value2;
};

void FNH_006_function(int arg) {
  FNH_006_Struct ndStruct;
  ndStruct.value = 10;
  free(&(ndStruct.value)); //@violation FREE_NON_HEAP  
  return; 
}
