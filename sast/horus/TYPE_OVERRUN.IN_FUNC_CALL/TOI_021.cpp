#include <stdlib.h>
#include <memory.h>

/* TOI_021 - src overrun with template */
template<size_t LENGTH>
class TOI_021_Class {
public:
  TOI_021_Class(char* str) {
    memcpy(src, str, LENGTH);
  }
  
  char* getSrc() { return src; }

private:
  char src[LENGTH];
};

void TOI_021_function1(){
  char src[] = "0123456789"; //sizeof(src) == 11

  TOI_021_Class<sizeof(src)> obj(src);
  char dst[256];

  memset(dst, 0, 256);

  memcpy(dst, obj.getSrc(), 4); //It's ok.

  memcpy(dst, obj.getSrc(), 15); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
