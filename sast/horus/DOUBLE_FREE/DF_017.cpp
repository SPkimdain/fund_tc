#include <stdio.h>

extern void *kalloc(int type, size_t size);
extern void kfree(int type, void *ptr);

/* DF_017 - 3rd party. */
int DF_017_function(int flag) {
  int * ptr = (int*)kalloc(0, 4);
  kfree(0, ptr);
  kfree(0, ptr); //@violation DOUBLE_FREE
  return flag;
} 
