#include <stdlib.h>

/* URP_001 - simple case */

void URP_001_function(){
  int x = 1;
  int y = 1073741824;

  int* arr = static_cast<int*>(malloc(x));

  int* arr2 = static_cast<int*>(malloc(y)); //@violation UNREASONABLE_PARAMETER 

  free(arr);
  free(arr2);
}

