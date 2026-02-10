#include <stdlib.h>
#include <string.h>

/* URP_005 - strncpy */

void URP_005_function(int flag, char* dst, char* src){
  int x = 1;
  int y = 1073741824;
  
  if(flag > 10) {
    strncpy(dst, src, x); //It's ok.
  }
  else {
    strncpy(dst, src, y); //@violation UNREASONABLE_PARAMETER 
  }

}

