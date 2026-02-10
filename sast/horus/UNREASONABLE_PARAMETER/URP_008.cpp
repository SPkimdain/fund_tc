#include <stdlib.h>
#include <memory.h>

/* URP_008 - large size struct, memcpy */

#define ARR_SIZE 5000000

struct URP_008_Struct {
  int value1[ARR_SIZE];
  int value2[ARR_SIZE];
  int value3[ARR_SIZE];
  int value4[ARR_SIZE];
  int value5[ARR_SIZE];
  int value6[ARR_SIZE];
  int value7[ARR_SIZE];
  int value8[ARR_SIZE];
  int value9[ARR_SIZE];
  int value10[ARR_SIZE];
};

void URP_008_function(URP_008_Struct* dst, URP_008_Struct* src){
  int size = 5;

  memcpy(dst, src, sizeof(URP_008_Struct)); //@violation UNREASONABLE_PARAMETER 
}

