#include <string.h>

/* TUDI_003 - simple memmove */
struct TUDI_003_Class {
  char dst[11];
};

int TUDI_003_function1(int offset) {
  if(offset > 0)  {
    return ++offset;
  }
  
  return -1;
}
void TUDI_003_function2(int flag, int offset) {
  char str[] = "0123456789"; //sizeof(src) == 11
  TUDI_003_Class obj;
  memcpy(obj.dst, str, sizeof(str));

  if(flag == 1) {
    memmove(obj.dst + 5, obj.dst + 2, 5); //It's ok.
  }
  else {
    if(offset < 3) {
      memmove(obj.dst + TUDI_003_function1(offset), str + 2, 3); //@violation TYPE_UNDERRUN.IN_FUNC_CALL
    }
  }
}
