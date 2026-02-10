#include <string.h>
#include <stdlib.h>

/* LM_030 - veriserve_03_02 from opus */
extern int g_num;

int LM_030_function()
{
  int i;
  int *p = (int *)malloc(sizeof(int)* 100);

  for(i = 0; i <= 10; i++) {
    if(g_num < i) {
      free(p);
      return 0;
    }
  }
  return 1; // LEAK.MEMORY
  // defect : leak of p when g_num is larger than 10
}//@violation LEAK.MEMORY
