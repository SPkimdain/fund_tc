#include <stdlib.h>

/* LM_006 - Access field  */
struct LM_006_Struct {
  int value;
  int* value2;
};

void LM_006_function(int arg) {
  LM_006_Struct ndStruct;
  ndStruct.value = 10;
  ndStruct.value2 = (int*)malloc(4);
  
  return;
} //@violation LEAK.MEMORY
