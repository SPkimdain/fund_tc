#include <stdlib.h>
#include <memory.h>

/* ODI_021 - src overrun */
void ODI_021_function1(){
  char src[] = "0123456789"; //sizeof(src) == 11
  char* temp = new char[sizeof(src)];
  if(temp == 0) {
    return;
  }

  memcpy(temp, src, sizeof(src));
  
  char dst[256];

  memset(dst, 0, 256);

  memcpy(dst, temp, 4); //It's ok.

  memcpy(dst, temp, 15); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] temp;
}
