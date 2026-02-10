#include <stdlib.h>

/* URP_012 - large size struct, calloc */

#define ARR_SIZE 2000000

struct URP_012_Struct {
  int value1[ARR_SIZE];
  int value2[ARR_SIZE];
  int value3[ARR_SIZE];
};

void URP_012_function(){
  int size = 5;

  URP_012_Struct* arr2 = static_cast<URP_012_Struct*>(calloc(size, sizeof(URP_012_Struct))); //@violation UNREASONABLE_PARAMETER 

  free(arr2);
}

