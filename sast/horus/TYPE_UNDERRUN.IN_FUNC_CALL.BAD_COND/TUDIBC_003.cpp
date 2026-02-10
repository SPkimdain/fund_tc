#include <string.h>

/* TUDIBC_003 - simple memmove */
struct TUDIBC_003_Class {
  char dst[11];
};

int TUDIBC_003_function1(int offset) {
  if(offset > 0)  {
    return ++offset;
  }
  
  return offset;
}
void TUDIBC_003_function2(int flag, int offset) {
  char str[] = "0123456789"; //sizeof(src) == 11
  TUDIBC_003_Class obj;
  memcpy(obj.dst, str, sizeof(str));

  if(flag == 1) {
    memmove(obj.dst + 5, obj.dst + 2, 5); //It's ok.
  }
  else {
    if(offset > -5) {
      memmove(obj.dst + TUDIBC_003_function1(offset), obj.dst + 2, 3); //@violation TYPE_UNDERRUN.IN_FUNC_CALL.BAD_COND
    }
  }
}
