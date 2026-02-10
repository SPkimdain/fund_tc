#include <stdlib.h>
#include <string.h>

/* URP_010 - strncat2 */

void URP_010_function(int size, char* dst, char* src){
  int* ptr = 0;
  if(size == -1) { //Wrong condition
    strncat(dst, src, size); //@violation UNREASONABLE_PARAMETER 
  }
}

