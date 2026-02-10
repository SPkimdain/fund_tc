#include <memory.h>

/* UDS_035 - unknown flow, from opus */
void UDS_035_function1(char *p) {
  *(p - 1) = 'a'; 
}

void UDS_035_function2(int i)
{
  char *p = 0;
  char buf[2];
  memset(buf, 0, sizeof(buf));

  if(i){
    p = buf; //This flow
  }
  else {
    p = buf + 1; //It's ok.
  }

  UDS_035_function1(p);	//@violation UNDERRUN.STATIC  
}

