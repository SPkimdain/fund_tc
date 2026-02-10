#include <stdlib.h>
#include <string.h>

/* URP_009 - strncat */

void URP_009_function(int flag, char* dst, char* src){
  int x = 1;
  int y = 1073741824;

  if(flag > 10) {
    strncat(dst, src, x); //It's ok.
  }
  else {
    strncat(dst, src, y); //@violation UNREASONABLE_PARAMETER 
  }

}

