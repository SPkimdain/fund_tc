#include <stdlib.h>

extern void tpreturn(int  rval, long  rcode, char  *data, long  len, long  flags);
extern void tpfree(char *ptr);

/* DF_021 - tmax false positive issue. */
int DF_021_function1(int flag) {
  int * ptr = (int*)malloc(4); 
  free(ptr);
  free(ptr); //@violation DOUBLE_FREE
  return flag;
} 


int DF_021_function2(int flag, int* x) {
  if(flag > 10) {
    tpfree(x);
    tpreturn(1, 0, "msg", 4, 0);
  }

  tpfree(x); //It's ok.

  return 0;
}

