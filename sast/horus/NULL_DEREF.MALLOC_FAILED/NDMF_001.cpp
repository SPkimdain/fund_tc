#include <stdlib.h>

struct NDMF_001_Struct {
  int* ptr;
};


void NDMF_001_function() {
  NDMF_001_Struct* p;
  p = (NDMF_001_Struct*)malloc(sizeof(NDMF_001_Struct));
  p->ptr = NULL;  //@violation NULL_DEREF.MALLOC_FAILED
  free(p);  
}

