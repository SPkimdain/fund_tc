#include <stdlib.h>

/* URP_002 - simple case2, wrong condition */

void URP_002_function(int size){
  int* ptr = 0;
  if(size == -1) { //Wrong condition
    ptr = static_cast<int*>(malloc(size)); //@violation UNREASONABLE_PARAMETER 
  }

  free(ptr);
}

