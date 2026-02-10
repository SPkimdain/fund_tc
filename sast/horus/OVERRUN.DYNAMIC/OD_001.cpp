#include <string.h>
#include <stdlib.h>

void OD_001_function() {
  char *dest;
  dest = (char*)malloc(12);
  
  if(dest == 0) {
    return;
  }
  
  (dest + 8)[6] = 'x'; //@violation OVERRUN.DYNAMIC
  free(dest);
}
