#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* UDD_057 - fgets return, empty string. */

void UDD_057_function() {
  char *dest;
  unsigned idx = 0;
  dest = (char*)malloc(12 * sizeof(char));

  if(dest == 0) {
    return;
  }

  if(fgets(dest, 12 * sizeof(char), stdin) == NULL) {
    free(dest);
    return;
  }

  char* ptr = 0;

  ptr = dest;
  idx = strlen(ptr);

  ptr[idx - 1] = '\0'; //@violation UNDERRUN.DYNAMIC
  free(dest);
}

