//@checker OVERRUN.STATIC.MEMSET

#include <stdlib.h>
#include <memory.h>

struct OVSMEM_Struct {  
  int val[20];
  int val2[30];
};

void OVSMEM_001_function(OVSMEM_Struct& obj, OVSMEM_Struct* obj2) {
  int a[20];
  memset(a, 0, sizeof(a)); //It's ok.

  memset(a, 0, sizeof(obj.val2)); //@violation OVERRUN.STATIC.MEMSET


  memcpy(a, obj2->val, sizeof(a)); //It's ok.

  memcpy(a, obj2->val, sizeof(obj2->val2)); //@violation OVERRUN.STATIC.MEMSET
}

