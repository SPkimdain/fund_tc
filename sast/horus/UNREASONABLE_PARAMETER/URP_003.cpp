#include <stdlib.h>

/* URP_003 - simple case3 */

void URP_003_function(int length, int flag){
  int* ptr = 0;
  if(flag > 10) {
    if(length != 0) {
      return;
    }
    else {
      /* length is 0 */
      ptr = static_cast<int*>(malloc(length)); //@violation UNREASONABLE_PARAMETER  
    }
  }

  if(ptr != 0) {
    free(ptr);
  }
}

