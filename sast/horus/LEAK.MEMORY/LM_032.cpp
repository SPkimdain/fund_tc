#include <string.h>
#include <stdlib.h>

/* LM_032 - veriserve_04_01 from opus */

struct LM_032_Struct1 {
  int i;
  long l;
  char c;
  char *pc;
};

struct LM_032_Struct2 {
  struct LM_032_Struct1 * ps2;
  int i;
  long l;
  char c;
};


int LM_032_function(int x, int y)
{
  struct LM_032_Struct2 rl04s1;
  if(x <= 0)
    return -1;

  rl04s1.ps2 = (LM_032_Struct1*)malloc(sizeof(struct LM_032_Struct1));
  if(rl04s1.ps2 == 0)
    return -2;

  rl04s1.ps2->pc = (char*)malloc(x);
  if(rl04s1.ps2->pc == 0){
    free(rl04s1.ps2);
    return -3;
  }

  free(rl04s1.ps2);
  return 0;  
  // defect (leak rl04s1.ps2->pc)
} //@violation LEAK.MEMORY
