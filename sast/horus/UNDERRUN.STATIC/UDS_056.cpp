#include <stdio.h>
#include <string.h>

enum { BUFFER_SIZE = 1024 };

/* UDS_056 - fgets return, empty string. */
void UDS_056_function() {
  char buf[BUFFER_SIZE];

  if(fgets(buf, sizeof(buf), stdin) == NULL) {
    return;
  }

  unsigned size = strlen(buf);

  buf[size - 1] = '\0'; //@violation UNDERRUN.STATIC
}
