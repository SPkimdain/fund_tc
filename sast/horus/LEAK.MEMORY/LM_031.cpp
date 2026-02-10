#include <string.h>
#include <stdlib.h>

/* LM_031 - veriserve_04_01 from opus */
extern int LM_031_function1(char *);

char* LM_031_function2(int size)
{
  if(size > 1000) {
    size = 1000;
  }
  
  char *p = (char*)malloc(size * 10);
  return p;
  
}

int LM_031_function3(int x, int y)
{
  if(y == 0) return -1;
  else {
    char *p;
    p = LM_031_function2(x + y);
    if(p == 0)
      return -1;
    if((x + y) > 50){
      p[50] = 0x00;
      LM_031_function1(p);
      free(p);
    }
  }       // defect (leak if (x+y)<=50) 
  return 0; //LEAK.MEMORY
} //@violation LEAK.MEMORY
