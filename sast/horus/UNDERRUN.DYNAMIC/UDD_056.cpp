/* UDD_056 - trace loop counter */

#include <string.h>
#include <stdlib.h>

void UDD_056_function() {
  char *dest;
  dest = (char*)malloc(12);

  if(dest == 0) {
    return;
  }

  int i = 0;
  int ret = 0;
  for(i = 100; i != 0; i--) {
    ret++;
  }


  dest[i - 1] = 'x'; //@violation UNDERRUN.DYNAMIC
  free(dest);
}

