#include <stdlib.h>

/* LM_029 - veriserve_01_03 from opus */
struct LM_029_Struct {
  char *p;
};
int LM_029_function(unsigned int size){

  LM_029_Struct srl;

  srl.p = (char*)malloc(size);
  if(srl.p == 0)  return 1;

  if(size > 100){
    free(srl.p);
    return 2;
  }

  return size;   
} //@violation LEAK.MEMORY
