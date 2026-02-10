#include <math.h>

#define CONSTANT_VALUE (80000000)


/* DBZ_063 - float result */
unsigned int DBZ_063_function(int flag) {
  int a = 100;
  return (unsigned int)ceilf((float)a / (1000000.0f / (float)CONSTANT_VALUE) / 1000.0f); //It's ok.
}

int DBZ_063_function2(int flag) {

  int ret = 10000;
  int div = 0;
  
  return ret / div; //@violation DIV_BY_ZERO
}

