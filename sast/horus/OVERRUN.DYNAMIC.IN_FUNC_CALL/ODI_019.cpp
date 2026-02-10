#include <string.h>

/* ODI_019 - multiple strcat */
void ODI_019_function(int flag) {
  float value = 10.5F;
  char src[] = "abcde"; //sizeof(src) == 6, len = 5
  char src2[] = "fghi"; //sizeof(src2) == 5, len = 4

  char* dst = new char[20];
  if(dst == 0) {
    return;
  }
  
  char* ret = 0;
  strcpy(dst, src2); //It's ok. len = 4 + 1

  strcat(dst, src2); //It's ok. len = 4 + 4 + 1
  strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 1
  strcat(dst, src); //It's ok. len = 4 + 4 + 5 + 5 + 1

  //len = 4 + 4 + 5 + 5 + 5 + 1 = 24
  strcat(dst, src); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  delete[] dst;
}

