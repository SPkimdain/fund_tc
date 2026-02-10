#include <stdlib.h>
#include <memory.h>

/* TOIBC_001 - simple memcpy */
struct TOIBC_001_Class {
  char dst[4];
};

void TOIBC_001_function1(int flag, int size){
  char* src = "asd"; //sizeof(src) == 4
  char* src2 = "abcd"; //sizeof(src2) == 5
  TOIBC_001_Class obj;

  if(size >= 0) {
    if(flag > 0) {
      memcpy(obj.dst, src, size); //Ignore.
    }
    else {
      if(size < 6) {
        memcpy(obj.dst, src2, size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
      }
    }
  }

  
}
