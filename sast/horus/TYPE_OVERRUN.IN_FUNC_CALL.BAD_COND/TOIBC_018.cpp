#include <string.h>

/* TOIBC_018 - strncat functions */
struct TOIBC_018_Class1 {
  char dst[6];
};

struct TOIBC_018_Class2 {
  TOIBC_018_Class1 buf;
  int size;
};

char* TOIBC_018_function1(char* dst, char* src, int size) {
  return strncat(dst, src, size);
}

void TOIBC_018_function2(int flag, int size) {
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  TOIBC_018_Class2 obj;
  char* ret = 0;
  strcpy(obj.buf.dst, src2); //It's ok.

  if(size == 1) {
    obj.size = size;
    //memory : 4 + 1 + 1, dst size is 6
    ret = TOIBC_018_function1(obj.buf.dst, src, obj.size); //It's ok.
  }
  else {
    if(size < 5) {
      obj.size = size;
      ret = TOIBC_018_function1(obj.buf.dst, src, obj.size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
    }
  }
}
