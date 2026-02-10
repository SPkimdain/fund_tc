#include <stdlib.h>
#include <memory.h>

/* OVI_001 - simple memcpy */
void OVI_001_function1(unsigned int x, int y){
  int flag = 0;
  char* src = "asd"; //sizeof(src) == 4
  char* src2 = "abcd"; //sizeof(src2) == 5
  char dst[4] = { 0, };
  int i = 0;
  if(x + 1 > 0){
    flag++;
  }
  else {
    flag += 2;
  }

  memcpy(dst, src, 4); //It's ok.

  memcpy(dst, src2, 5); //@violation OVERRUN.STATIC.IN_FUNC_CALL
}
