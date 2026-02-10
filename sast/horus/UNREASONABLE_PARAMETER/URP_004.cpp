#include <stdlib.h>

/* URP_004 - large size struct */

#define ARR_SIZE 2000000

struct URP_004_Struct {
  int value1[ARR_SIZE];
  int value2[ARR_SIZE];
  int value3[ARR_SIZE];
};

void URP_004_function(){
  int size = 5;

  URP_004_Struct* arr2 = static_cast<URP_004_Struct*>(malloc(size * sizeof(URP_004_Struct))); //@violation UNREASONABLE_PARAMETER 

  free(arr2);
}

