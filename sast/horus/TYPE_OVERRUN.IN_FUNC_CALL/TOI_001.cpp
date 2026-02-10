#include <stdlib.h>
#include <memory.h>

/* TOI_001 - simple memcpy */
struct TOI_001_Class {
  char dst[4];
};

void TOI_001_function1(unsigned int x, int y){
  int flag = 0;
  char* src = "asd"; //sizeof(src) == 4
  char* src2 = "abcd"; //sizeof(src2) == 5
  TOI_001_Class obj;

  int i = 0;
  if(x + 1 > 0){
    flag++;
  }
  else {
    flag += 2;
  }

  memcpy(obj.dst, src, 4); //It's ok.

  memcpy(obj.dst, src2, 5); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
