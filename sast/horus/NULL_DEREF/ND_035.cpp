#include <memory.h>

/* ND_035 - unknown flow, from opus */
void ND_035_function1(char *p) {
  // if i is 0.
  p[0] = 'a';
  
}

void ND_035_function2(int i)
{
  char *p = 0;
  char buf[10];
  memset(buf, 0, sizeof(buf));

  if(i){
    p = buf;
  }
  else {
    ;
  }

  ND_035_function1(p);	 //@violation NULL_DEREF
}

