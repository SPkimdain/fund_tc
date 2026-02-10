#include <stdlib.h>

/* OD_035 - unknown flow, from opus */
void OD_035_function1(char *p) {
  *(p + 1) = 'a'; 
}

void OD_035_function2(int i)
{
  char *p = 0;
  char* buf = (char*)malloc(2 * sizeof(char));
  if(buf == 0) {
    return;
  }

  if(i){
    p = buf;
  }
  else {
    p = buf + 1; //This flow
  }

  OD_035_function1(p);	//@violation OVERRUN.DYNAMIC  

  free(buf);
}

