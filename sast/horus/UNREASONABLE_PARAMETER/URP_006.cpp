#include <stdlib.h>
#include <string.h>

/* URP_006 - strncpy2 */

void URP_006_function(int size, char* dst, char* src){
  int* ptr = 0;
  if(size == -1) { //Wrong condition
    strncpy(dst, src, size); //@violation UNREASONABLE_PARAMETER 
  }
}

