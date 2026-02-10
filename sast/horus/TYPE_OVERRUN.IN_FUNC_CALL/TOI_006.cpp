#include <string.h>

/* TOI_006 - simple strcat */
struct TOI_006_Class {
  char dst[6];
};

void TOI_006_function(int flag) {
  TOI_006_Class obj;
  char src[] = "abcde"; //sizeof(src) == 6
  char src2[] = "fghi"; //sizeof(src2) == 5
  char src3[] = "1"; //sizeof(src3) == 2
  char* ret = 0;
  
  strcpy(obj.dst, src2); //It's ok.
  
  if(flag > 0) {
    //memory : 4 + 1 + 1, dst size is 6
    ret = strcat(obj.dst, src3); //It's ok
  }
  else {
    //memory : 4 + 5 + 1, dst size is 6
    ret = strcat(obj.dst, src); //@violation TYPE_OVERRUN.IN_FUNC_CALL
  }
}
