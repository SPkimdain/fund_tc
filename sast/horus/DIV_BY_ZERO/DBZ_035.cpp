#include <memory.h>

/* DBZ_035 - unknown flow, from opus */
void DBZ_035_function1(int value) {
  // if i is 0.
  int ret = 1000 / value; // DIV_BY_ZERO
  
}

void DBZ_035_function2(int i)
{
  int x = 100;
  if(i){
    x = 0;
  }
  else {
    x++;
  }

  DBZ_035_function1(x); //@violation DIV_BY_ZERO
}

