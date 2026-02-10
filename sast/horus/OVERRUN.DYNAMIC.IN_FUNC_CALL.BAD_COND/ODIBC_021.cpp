#include <stdlib.h>
#include <memory.h>

/* ODIBC_021 - src overrun */
void ODIBC_021_function1(int size, int tempSize){
  if(tempSize < 12)  {
    char src[] = "0123456789"; //sizeof(src) == 11
    char* temp = new char[tempSize];
    if(temp == 0) {
      return;
    }
    char dst[256];

    memcpy(temp, src, tempSize);

    memset(dst, 0, 256);

    if(size == 4) {
      memcpy(dst, temp, 4); //It's ok.
    }
    else if(size < 15) {
      memcpy(dst, temp, size); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL.BAD_COND
    }

    delete[] temp;
  }
}
