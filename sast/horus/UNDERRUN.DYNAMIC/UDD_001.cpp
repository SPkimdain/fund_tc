#include <string.h>
#include <stdlib.h>

void UDD_001_function() {
  char *dest;
  dest = (char*)malloc(12);
  
  if(dest == 0) {
    return;
  }
  
  (dest + 3)[-4] = 'x'; //@violation UNDERRUN.DYNAMIC
  free(dest);
}
