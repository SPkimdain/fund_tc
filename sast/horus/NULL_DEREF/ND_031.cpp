#include <stdlib.h>
#include <memory.h>

/* ND_031 - bash example1 from opus */
void ND_031_function1(unsigned int x, int y){
  int flag = 0;
  char *str = 0;
  char *dst = (char*)malloc(100);
  int i = 0;
  if(x + 1 > 0){
    flag++;
  }
  else {
    flag += 2;
  }
  if(dst == 0) return;
  memcpy(dst, str, 1); //@violation NULL_DEREF

  free(dst);
}
