#include <memory.h>

/* TOIBC_002 - simple memset */
struct TOIBC_002_Class {
  char dst1[20];
  char dst2[30];
};

int TOIBC_002_function(int index) {
  TOIBC_002_Class obj;

  if(index >= 0 && index <= 21) {
    memset(obj.dst2, 50, index); //It's ok.
    
    memset(obj.dst1, 20, index); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND

    memset(obj.dst1, 20, index); //Ignore.
  }

  return 0;
}
