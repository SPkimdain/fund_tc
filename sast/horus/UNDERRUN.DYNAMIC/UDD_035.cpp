#include <stdlib.h>

/* UDD_035 - unknown flow, from opus */
void UDD_035_function1(char *p) {
  *(p - 1) = 'a'; 
}

void UDD_035_function2(int i)
{
  char *p = 0;
  char* buf = (char*)malloc(2 * sizeof(char));
  if(buf == 0) {
    return;
  }

  if(i){
    p = buf; //This flow
  }
  else {
    p = buf + 1; 
  }

  UDD_035_function1(p);	//@violation UNDERRUN.DYNAMIC  

  free(buf);
}

