#include <memory.h>

/* OV_035 - unknown flow, from opus */
void OV_035_function1(char *p) {
  *(p + 1) = 'a'; 
}

void OV_035_function2(int i)
{
  char *p = 0;
  char buf[2];
  memset(buf, 0, sizeof(buf));

  if(i){
    p = buf;
  }
  else {
    p = buf + 1; //This flow
  }

  OV_035_function1(p);	//@violation OVERRUN.STATIC  
}

