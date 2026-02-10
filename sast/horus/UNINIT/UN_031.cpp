#pragma warning(disable : 4700)

#include <stdlib.h>
#include <memory.h>

/* UN_031 - uninit_problem1 from opus */
int UN_031_function1(unsigned int x){
  int _y;
  int z = 0;
  int a = 10;

  if(x > 0) a = x + 100;

  z = a + x + _y; //@violation UNINIT
  return z;
}
