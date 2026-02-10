#include <stdlib.h>
#include <memory.h>

/* TOIBC_021 - src overrun */
template<size_t LENGTH>
class TOIBC_021_Class {
public:
  TOIBC_021_Class(char* str) {
    memcpy(src, str, LENGTH);
  }

  char* getSrc() { return src; }

private:
  char src[LENGTH];
};

void TOIBC_021_function1(int size){
  char src[] = "0123456789"; //sizeof(src) == 11
  TOIBC_021_Class<sizeof(src)> obj(src);
  char dst[256];

  memset(dst, 0, 256);

  if(size == 4) {
    memcpy(dst, obj.getSrc(), 4); //It's ok.
  }
  else if(size < 15) {
    memcpy(dst, obj.getSrc(), size); //@violation TYPE_OVERRUN.IN_FUNC_CALL.BAD_COND
  }
}
