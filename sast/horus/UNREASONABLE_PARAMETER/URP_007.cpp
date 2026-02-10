#include <stdlib.h>
#include <string.h>

/* URP_007 - strncpy3 */

void URP_007_function(int length, int flag, char* dst, char* src){
  int* ptr = 0;
  if(flag > 10) {
    if(length != 0) {
      return;
    }
    else {
      /* length is 0 */
      strncpy(dst, src, length); //@violation UNREASONABLE_PARAMETER  
    }
  }
}

