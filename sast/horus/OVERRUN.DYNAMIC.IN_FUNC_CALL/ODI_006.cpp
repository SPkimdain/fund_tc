#include <string.h>

/* ODI_006 - simple strcat */
void ODI_006_function(int flag) {
  char* dst = new char[6];
  if(dst == 0) {
    return;
  }

  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char src3[] = "1"; //sizeof(src3) == 2
  char* ret = 0;
  
  strcpy(dst, src2); //It's ok.
  
  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strcat(dst, src3); //It's ok
  }
  else {
    //memory : 4 + 5 + 1, dst size is 6
    ret = strcat(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
  }

  delete[] dst;
}
