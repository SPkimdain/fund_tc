#include <stdlib.h>

/* UAF_006 - Access field  */
struct UAF_006_Struct {
  int value;
  int* value2;
};

void UAF_006_function(int arg) {
  UAF_006_Struct ndStruct;
  ndStruct.value = 10;
  ndStruct.value2 = (int*)malloc(4);

  if(ndStruct.value2 == 0) {
    return;
  }
  
  free(ndStruct.value2);

  *ndStruct.value2 = 10; //@violation USE_AFTER_FREE
}
